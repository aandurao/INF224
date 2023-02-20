//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <sstream>
#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MediaGroup.h"
#include "Database.h"
#include "tcpserver.h"
using namespace std;

#define SERVER_VERSION

#ifndef SERVER_VERSION

int main(int argc, const char* argv[])
{
    std::cout << "Starting MultiMediaPlayer !\n\n";


    Database * db = new Database();
    MediaGroupPtr group1 = db->makeGroup("Group 1");
    MediaObjectPtr garden = db->makePhoto("Garden", "resources/garden.jpg", 10.0, 10.0);
    group1->push_back(garden);
    db->findMediaGroup("Group 1", std::cout);
    db->deleteMediaGroup("Group 1");

    return 0;
}
#else

int main(int argc, const char* argv[])
{
    int port = 3331; //Default value for server port
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    shared_ptr<Database> db(new Database());

    // Parse the port number from the command-line argument
    port = std::atoi(argv[1]);

    // Create the TCPServer
    auto* server =
            new TCPServer([&](std::string const& request, std::string& response) {

        // The request sent by the client to the server
        std::cout << "Request received : " << request << std::endl;

        std::stringstream input_stream(request);
        std::string type;
        std::string scope;
        std::string name;

        input_stream >> type >>  scope >> name;

        // Check if all extractions were successful
        if (input_stream.fail()) {
            std::cerr << "Failed to parse input string" << std::endl;
            response = "Failed to parse input request";
            return true;
        }

        if(name == Database::SEARCH) {
            if (scope == Database::MEDIA) {
                std::ostringstream oss;
                db->findMediaObject(name, oss);
                response = oss.str();
            } else if (scope == Database::GROUP) {
                std::ostringstream oss;
                db->findMediaGroup(name, oss);
                response = oss.str();
            } else {
                std::cerr << "Unrecgonized scope";
                response = "Failed to parse input request;";
                return true;
            }
        }else if (name == Database::PLAY) {
            if (scope == Database::MEDIA) {
                db->playMediaObject(name);
                response = "Played media " + name + " on the server !;";
            }else {
                std::cerr << "Unrecgonized scope";
                response = "Failed to parse input request;";
                return true;
            }
        } else if (name == Database::DEL) {
            if (scope == Database::MEDIA) {
                db->deleteMediaObject(name);
                response = "Deleted media " + name + " on the server !;";
            } else if (scope == Database::GROUP) {
                db->deleteMediaGroup(name);
                response = "Deleted group " + name + " on the server !;";
            } else {
                std::cerr << "Unrecgonized scope";
                response = "Failed to parse input request;";
                return true;
            }
        }

        // Returning false would close the connection with the client
        return true;
    });
    // Before starting infinite loop of the server.
    std::cout << "Starting MultiMediaPlayer Server on port " << port << std::endl;

    int status = server->run(port);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << port << std::endl;
        return 1;
    }

    return 0;
}

#endif