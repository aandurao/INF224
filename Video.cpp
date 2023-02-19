//
// Created by Antoine on 12/27/2022.
//

#include "Video.h"

void Video::setDuration(const int d) {
    duration = d;
}

int Video::getDuration() const {return duration;}

void Video::display(std::ostream& output) const {
    MediaObject::display(output);
    output << "Type : Video \nDuration : " + std::to_string(duration) << std::endl;
}

void Video::play() const {
    if(pathname != "") {
        std::string arg;
        arg = "mpv " + pathname + " &";
        std::system(arg.data());
    }
}