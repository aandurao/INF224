//
// Created by Antoine on 1/3/2023.
//

#ifndef INF224_FILM_H
#define INF224_FILM_H

#include "Video.h"

class Film : public Video {

protected:
    unsigned int chapters_num{};
    int * chapters{};

public:
    /**
     * Default constructor for Film
     */
    Film() : Video("Film", "", 0){};

    /**
     * Constructor for Video
     * @param n name of the Film object
     * @param p path to the file linked with the Film object
     * @param d duration of the film
     * @param number number of chapters
     * @param chapters array of int containing the duration of each chapter
     */
    Film(const std::string n, const std::string p, const unsigned int d, unsigned int number, int * chaps) : Video(n,p, d), chapters_num(number), chapters(nullptr) {
        setChapters(number, chaps);
    }

    int * getChapters();

    int getChaptersNumber();

    void setChapters(unsigned int n_chaps, int * chaps);

    void display(std::ostream& output) const override;

    ~Film();

    Film& operator=(const Film& copied) {
        Video::operator=(copied);
        chapters = nullptr;
        chapters_num = copied.chapters_num + 1;
        setChapters(copied.chapters_num, copied.chapters);
        return *this;
    }
};



#endif //INF224_FILM_H
