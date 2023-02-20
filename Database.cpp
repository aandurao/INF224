//
// Created by Antoine on 2/19/2023.
//

#include "Database.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

const std::string Database::SEARCH = "SEARCH";
const std::string Database::PLAY = "PLAY";
const std::string Database::DEL = "DELETE";
const std::string Database::MEDIA = "MEDIA";
const std::string Database::GROUP = "GROUP";

MediaObjectPtr Database::makeFilm(const std::string n, const std::string p, const unsigned int d, unsigned int number, int * chaps) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Film(n,p,d,number,chaps)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Film with same name : " << n << std::endl;
        throw std::exception();
    }
}

MediaObjectPtr Database::makePhoto(const std::string n, const std::string p, const float lat, const float lon) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Photo(n,p, lat, lon)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Photo with same name : " << n << std::endl;
        throw std::exception();
    }
}

MediaObjectPtr Database::makeVideo(const std::string n, const std::string p, const unsigned int d) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Video(n,p, d)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Video with same name : " << n << std::endl;
        throw std::exception();
    }
}

MediaGroupPtr Database::makeGroup(const std::string name){
    if(groups.find(name) == groups.end()) {
        groups.insert(std::pair<std::string,MediaGroupPtr>(name, new MediaGroup(name)));
        return groups[name];
    } else {
        std::cerr << "Can't create another MediaGroup with same name : " << name << std::endl;
        throw std::exception();
    }
}

void Database::findMediaGroup(const std::string name, std::ostream& output) {
    auto found_group = groups.find(name);
    if(found_group != groups.end()) {
        ((const MediaGroupPtr &) found_group->second)->display_elements(output);
    } else {
        output << "Couldn't find MediaGroup named : " << name << " !" << std::endl;
    }
}

void Database::findMediaObject(const std::string name, std::ostream& output) {
    auto found_object = media_objects.find(name);
    if(found_object != media_objects.end()) {
        ((const MediaObjectPtr &) found_object->second)->display(output);
    }else {
        output << "Couldn't find MediaObject named : " << name << " !" << std::endl;
    }
}

void Database::playMediaObject(std::string name) {
    auto found_object = media_objects.find(name);
    if(found_object != media_objects.end()) {
        ((const MediaObjectPtr &) found_object->first)->play();
    } else {
        std::cerr << "Couldn't find MediaObject named : " << name << " !" << std::endl;
    }
}

void Database::deleteMediaObject(const std::string _name) {
    auto md = media_objects.find(_name);
    if (md == media_objects.end()) {
        std::cerr << "DB: Media with the same name does not exist." << std::endl;
        return;
    } else {
        media_objects.erase(md);
        return;
    }
}

void Database::deleteMediaGroup(const std::string _name) {
    auto md = groups.find(_name);
    if (md == groups.end()) {
        std::cerr << "DB: Group with the same name does not exist." << std::endl;
        return;
    } else {
        groups.erase(md);
        return;
    }
}