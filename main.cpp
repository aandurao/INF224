//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "MediaGroup.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Starting MultiMediaPlayer !\n\n";
    MediaObjectPtr* objects = new MediaObjectPtr[3];
    unsigned int count = 0;
    int * chapters = new int[3]{1,1,2};
    objects[count++] = make_shared<Photo>("Garden", "resources/garden.jpg", 10, 10);
    objects[count++] = make_shared<Photo>("Chile", "resources/chile.jpg", 10, 10);
    objects[count++] = make_shared<Film>("Gael ce bg", "resources/C0041.MP4", 10, 3, chapters);

    MediaGroup  * group1 = new MediaGroup("Group 1");
    group1->push_back(objects[0]);
    group1->push_back(objects[1]);

    MediaGroup * group2 = new MediaGroup("Group 2");
    group1->push_back(objects[1]);
    group1->push_back(objects[2]);

    MediaGroup * group3 = new MediaGroup("Group 3");
    group1->push_back(objects[2]);
    group1->push_back(objects[0]);

    group1->display_elements(std::cout);
    group2->display_elements(std::cout);
    group3->display_elements(std::cout);

    group1->remove(objects[0]);
    group3->remove(objects[0]);

    /**
    for(unsigned  int k=0; k<count; k++){
        objects[k]->display(std::cout);
        std::cout << "------------\n";
    }*/

    delete [] objects;
    return 0;
}
