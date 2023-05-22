#include <iostream>
#include "database.h"


int main() {
    Data sep200;

    //these next lines initialize the database with historical data
    Student students[2] = { {"Albert", "Einstein", 3.5},
                           {"Isaac", "Newton", 3.6} };
    sep200.list_students = new Student[2];
    sep200.list_students[0] = students[0];
    sep200.list_students[1] = students[1];
    sep200.size = 2;
    //end of database initialization --------

    int size;
    char choice;

    while (true) {
        std::cout << "Create a list (c), list all students (l), or quit (q)?";
        std::cin >> choice;
        if (choice == 'c') {
            std::cout << "How many students in this list?";
            std::cin >> size;
            if (!create_list(sep200, size)) {
                std::cout << "Could not create_list. Try again." << std::endl;
                std::cin.clear();
            }
        }
        else if (choice == 'l') {
            list_students(sep200);
        }
        else {
            free_memory(sep200);
            break;
        }
    }

    return 0;
}