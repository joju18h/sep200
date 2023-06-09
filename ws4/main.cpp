#include <iostream>
#include "movies.h"

int main() {

    Movies movie_catalog;
    char answer;

    while (true) {
        std::cout << "What do you want to do? " << 
        " Add movie (a), display catalog (d), or quit (q)? ";
        std::cin >> answer;
        if (answer == 'a') {
            if (movie_catalog.add_movie()) {
                std::cout << "Movie added to list" << std::endl;
            } else {
                std::cout << "Out of memory!" << std::endl;
            }
        } else if (answer == 'd') {
            movie_catalog.display_movies();  
        } else if (answer == 'q') {
            std::cout << "Bye" << std::endl;
            break;
        }
    }
    
    return 0;
}