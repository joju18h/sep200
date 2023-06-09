#include <iostream>
#include <new>
#include "movies.h"

Movie *Movies::head_ = nullptr;
Movie *Movies::tail_ = nullptr;
int Movies::number_movies = 0;

Movies::Movies(){
    std::cout << "Your movie catalog has been created" << std::endl;
}


bool Movies::add_movie(){
    bool retval = false;
    Movie *added_movie = new (std::nothrow) Movie();
    if(added_movie != nullptr){
        std::cout << "Enter the name of the movie: ";
        std::cin.ignore(); //flushing newline
        std::cin.getline(added_movie->title, 32);

        std::cout << "Enter a rating out of 5: ";
        std::cin >> added_movie->rating;

        added_movie->next = nullptr;

        if(number_movies == 0){
            head_ = added_movie;
            tail_ = added_movie;
        }
        else{
            tail_->next = added_movie;
            tail_ = added_movie;
        }
        number_movies++;
        retval = true;
    }
    return retval;
}

void Movies::display_movies() const{
    Movie *read_head = head_;
    while(read_head != nullptr){
        std::cout << "Title: " << read_head->title << std::endl
                  << "Rating: " << read_head->rating << std::endl;
        std::cout << std::endl;
        read_head = read_head->next;
    }
}

Movies::~Movies(){
    Movie *read_head = head_;
    while(read_head != nullptr){
        Movie *next = read_head->next;
        delete read_head;
        read_head = next;
    }
}