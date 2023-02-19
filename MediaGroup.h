//
// Created by Antoine on 2/19/2023.
//

#ifndef INF224_MEDIAGROUP_H
#define INF224_MEDIAGROUP_H

#include <list>
#include <memory>
#include "MediaObject.h"

using MediaObjectPtr = std::shared_ptr<MediaObject>;
class MediaGroup : public std::list<MediaObjectPtr> {

private:
    std::string name;
public:
    MediaGroup(const std::string name) : name(name) {};

    std::string getName() const;

    void display_elements(std::ostream& output) const;

    ~MediaGroup();

};


#endif //INF224_MEDIAGROUP_H
