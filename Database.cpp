//
// Created by Antoine on 2/19/2023.
//

#include "Database.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

MediaObjectPtr Database::makeFilm(const std::string n, const std::string p, const unsigned int d, unsigned int number, int * chaps) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Film(n,p,d,number,chaps)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Film with same name : " << n << endl;
    }
}

MediaObjectPtr Database::makePhoto(const std::string n, const std::string p, const float lat, const float lon) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Photo(n,p, lat, lon)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Photo with same name : " << n << endl;
    }
}

MediaObjectPtr Database::makeVideo(const std::string n, const std::string p, const unsigned int d) {
    if(media_objects.find(n) == media_objects.end()) {
        media_objects.insert(std::pair<std::string,MediaObjectPtr>(n, new Video(n,p, d)));
        return media_objects[n];
    } else {
        std::cerr << "Can't create another Video with same name : " << n << endl;
    }
}



