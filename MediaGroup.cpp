//
// Created by Antoine on 2/19/2023.
//

#include "MediaGroup.h"

std::string MediaGroup::getName() const {return this->name;}

void MediaGroup::display_elements(std::ostream& output) const {
    output << "Elements of " + this->name + " are :" << std::endl;
    for (auto& media : *this) {
        media->display(output);
        output << std::endl;
    }
    output << "--------\n";
}

MediaGroup::~MediaGroup() {
    std::cout << "Group named " << this->name << " is being deleted !" << std::endl;
}