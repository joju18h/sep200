#ifndef MOVIES_H
#define MOVIES_H

#define SIZE 32

struct Movie{
    char title[SIZE];
    float rating;
    Movie *next;
};

class Movies{

    static Movie *head_;
    static Movie *tail_;
    static int number_movies;

    public:
        Movies();
        ~Movies();
        bool add_movie();
        void display_movies() const;
};

#endif //MOVIES_H