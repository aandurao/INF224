//
// Created by Antoine on 2/19/2023.
//

#ifndef INF224_DATABASE_H
#define INF224_DATABASE_H

#include <map>
#include "MediaGroup.h"

class Database {

private:
    media_objects = std::map<std::string, MediaObjectPtr>;
public:
    Database() {};
    MediaObjectPtr makePhoto(const std::string n, const std::string p, const float lat, const float lon);
    MediaObjectPtr makeVideo(const std::string n, const std::string p, const unsigned int d);
    MediaObjectPtr makeFilm(const std::string n, const std::string p, const unsigned int d, unsigned int number, int * chaps);
};


#endif //INF224_DATABASE_H
