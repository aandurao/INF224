//
// Created by Antoine on 12/27/2022.
//

#ifndef INF224_PHOTO_H
#define INF224_PHOTO_H

#include <string>
#include <iostream>
#include "MediaObject.h"


class Photo : public MediaObject {

protected:

    float lat{};
    float lon{};

public:

    /**
     * Default constructor for Videos
     */
    Photo() : MediaObject("Photo", ""), lat(0), lon(0) {};

    Photo(const std::string n, const std::string p, const float lat, const float lon) : MediaObject(n,p), lat(lat), lon(lon) {};

    /**
     *
     * @return the latitude of this Photo object
     */
    float getLatitude();

    /**
     *
     * @return the longitude of this Photo object
     */
    float getLongitude();

    /**
     * Sets the latitude of this Photo object
     * @param la the latitude
     */
    void setLatitude(const float la);

    /**
     * Sets the longitude of this Photo object
     * @param lo the longitude
     */
    void setLongitude(const float lo);

    void display(std::ostream& output) const override;

    void play() const override;

    ~Photo();
};


#endif //INF224_PHOTO_H
