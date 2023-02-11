//
// Created by Antoine on 1/3/2023.
//

#include "Film.h"

int Film::getChaptersNumber(){
    return chapters_num;
}

int * Film::getChapters() {
    int * ret = new int[chapters_num];

    for (unsigned int i=0; i<chapters_num; i++) {
        ret[i] = chapters[i];
    }

    return ret;
}

void Film::setChapters(unsigned int n_chaps, int * chaps) {
    if(n_chaps != chapters_num) {
        delete [] chapters;
        chapters_num = n_chaps;
        chapters = new int[chapters_num];
    }

    for (unsigned int i=0; i<chapters_num; i++) {
        chapters[i] = chaps[i];
    }
}

void Film::display(std::ostream &output) const {
    MediaObject::display(output);
    output << "Type : Film Duration : " + std::to_string(duration) + " Number of chapters : " + std::to_string(chapters_num) << std::endl;
    for(unsigned int i=0; i<chapters_num; i++) {
        output << "Duration of chapter " << i << " : " << chapters[i] << std::endl;
    }
}