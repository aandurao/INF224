//
// Created by Antoine on 12/27/2022.
//

#include "Photo.h"

void Photo::setLatitude(const float la) {
    lat = la;
}

void Photo::setLongitude(const float lo) {
    lon = lo;
}

void Photo::display(std::ostream& output) const {
    MediaObject::display(output);
    output << "Type : Photo Latitude : " + std::to_string(lat) + " Longitude : " + std::to_string(lon);
}

void Photo::play() const {
    if(pathname != "") {
        std::string arg;
        std::cout << "Playing " + pathname;
        arg = "imagej " + pathname + " &";
        std::system(arg.data());
    }
}