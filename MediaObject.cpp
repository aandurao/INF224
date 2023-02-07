//
// Created by Antoine on 12/25/2022.
//

#include <string>
#include <iostream>
#include "MediaObject.h"

MediaObject::MediaObject(){
    name = "MediaObject";
    pathname = "";
}

MediaObject::MediaObject(const std::string n,const std::string p) {
    name = n;
    pathname = p;
}

MediaObject::~MediaObject(){
    std::cerr<<"Getting rid of MediaObject : " + MediaObject::getName();
}

std::string MediaObject::getName() const {
    return name;
}

void MediaObject::setName(const std::string n) {
    name = n;
}

std::string MediaObject::getPathname() const {
    return pathname;
}

void MediaObject::setPathname(const std::string p) {
    pathname = p;
}

void MediaObject::display(std::ostream& output)  const {
    output << "MediaObject : " + name + " Location : " + pathname << std::endl;
}

void MediaObject::play() const {
    this->display(std::cerr);
    std:cerr << "This function shouldn't have been called, check for an error." << std::endl;
}