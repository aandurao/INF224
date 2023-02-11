//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout<< "Here";
    std::cout << "Starting MultiMediaPlayer !";
    MediaObject ** objects = new MediaObject * [3];
    unsigned int count = 0;
    objects[count++] = new Photo("Garden", "resources/garden.jpg", 10, 10);
    objects[count++] = new Photo("Chile", "resources/chile.jpg", 10, 10);

    int * chapters = new int[3]{1,1,2};

    delete [] chapters;
    for(unsigned  int k=0; k<count; k++){
        objects[k]->display(std::cout);
        objects[k]->play();
        std::cout << "\n------------\n";
    }
    delete [] objects;
    return 0;
}
