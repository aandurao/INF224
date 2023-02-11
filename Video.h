//
// Created by Antoine on 12/27/2022.
//

#ifndef INF224_VIDEO_H
#define INF224_VIDEO_H

#include <string>
#include <iostream>
#include "MediaObject.h"

/**
 * @brief Object representing a video.
 * Inherits from MediaObject.
 */
class Video : public MediaObject  {
protected:
    // Duration of the video.
    unsigned int duration{};
public:
    /**
     * Default constructor for Video
     */
    Video() : MediaObject("Video", ""), duration(0) {};

    /**
     * Constructor for Video
     * @param n name of the Video object
     * @param p path to the file linked with the Video object
     * @param d duration of the video
     */
    Video(const std::string n, const std::string p, const unsigned int d) : MediaObject(n,p), duration(d) {}

    /**
     * @return the duration of the video (in seconds).
     */
    int getDuration() const;

    /**
     * Set the duration of the video.
     * @param d the duration (in seconds)
     */
    void setDuration(const int d);

    void display(std::ostream& output) const override;

    void play() const override;
};


#endif //INF224_VIDEO_H
