//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Photo.h"
#include "Video.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Starting MultiMediaPlayer !" << std::endl;
    MediaObject ** objects = new MediaObject * [3];
    unsigned int count = 0;
    objects[count++] = new Photo("Garden", "resources/garden.jpg", 10, 10);
    objects[count++] = new Photo("Chile", "resources/chile.jpg", 10, 10);
    objects[count++] = new Video("MiamMarcheville", "resources/C0041.MP4", 4);
    for(unsigned  int k=0; k<count; k++){
        objects[k]->display(std::cout);
        objects[k]->play();
    }
    delete [] objects;
    return 0;
}
