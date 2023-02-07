//
// Created by Antoine on 12/25/2022.
//

#ifndef INF224_MEDIAOBJECT_H
#define INF224_MEDIAOBJECT_H

#include "string"
#include "iostream"

/**
 * @brief Generic container for media objects.
 * Contains the name of the object and the path to the file related to it.
 */
class MediaObject {

protected:
    // Name of the media object.
    std::string name{};
    // Path to the file related to this MediaObject.
    std::string pathname{};
public:
    /**
     * Default constructor for MediaObject.
     */
    MediaObject();
    /**
     * Constructor for MediaObject.
     *
     * @param n name of this MediaObject
     * @param p path to the file linked to this MediaObject
     */
    MediaObject(const std::string n, const std::string p);
    /**
     * Destructor for MediaObject
     */
    virtual ~MediaObject();
    /**
     * Sets the name of this MediaObject
     * @param n name of the MediaObject
     */
    void setName(std::string n);
    /**
     *
     * @return the name of this MediaObject
     */
    std::string getName() const;
    /**
     * Sets the path to the file linked to this MediaObject
     * @param p path to the file
     */
    void setPathname(std::string p);
    /**
     *
     * @return the path to the file linked to this MediaObject
     */
    std::string getPathname() const;
    /**
     * Prints a description of this MediaObject in the specified output stream
     * @param output the ostream in which the MediaObject will output its description
     */
    virtual void display(std::ostream& output) const;

    /**
     * Plays the media contained in this MediaObject.
     */
    virtual void play() const;
};


#endif //INF224_MEDIAOBJECT_H
