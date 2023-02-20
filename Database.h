//
// Created by Antoine on 2/19/2023.
//

#ifndef INF224_DATABASE_H
#define INF224_DATABASE_H

#include <map>
#include "MediaGroup.h"

using MediaGroupPtr = std::shared_ptr<MediaGroup>;
class Database {

private:
    std::map<std::string, MediaObjectPtr> media_objects;
    std::map<std::string, MediaGroupPtr> groups;
public:
    static const std::string SEARCH;
    static const std::string PLAY;
    static const std::string DEL;
    static const std::string MEDIA;
    static const std::string GROUP;
    Database() {};
    MediaObjectPtr makePhoto(const std::string n, const std::string p, const float lat, const float lon);
    MediaObjectPtr makeVideo(const std::string n, const std::string p, const unsigned int d);
    MediaObjectPtr makeFilm(const std::string n, const std::string p, const unsigned int d, unsigned int number, int * chaps);
    MediaGroupPtr makeGroup(const std::string name);
    void findMediaObject(const std::string name, std::ostream& output);
    void findMediaGroup(const std::string name, std::ostream& output);
    void playMediaObject(const std::string name);
    void deleteMediaObject(const std::string name);
    void deleteMediaGroup(const std::string name);
    int process(std::string const& request, std::string& response);
};


#endif //INF224_DATABASE_H
