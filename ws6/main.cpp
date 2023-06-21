#include <iostream>
#include<string>
#include "club.h"

int main() {

    Member john, paul, ben;
    Club sep200, sep200a, sep200b;

    john.id = 12;
    john.email = "john@gmail.ca";

    paul.id = 37;
    paul.email = "paul@gmail.ca";

    ben.id = 38;
    ben.email = "ben@gmail.ca";

    sep200.add_member(john);
    sep200.add_member(paul);
    sep200.list_members();
    std::cout << " ---- end of list 1 ---- " << std::endl;
    
    //deep copy via overloaded assignment
    sep200a = sep200;
    sep200a.add_member(ben);
    sep200a.list_members();
    std::cout << " ---- end of list 3 ---- " << std::endl;

    //retrieving data via file IO
    sep200.save_club("sep200.txt");
    sep200b.retrieve_club("sep200.txt");
    sep200b.list_members();
    std::cout << " ---- end of retrieved list ---- " << std::endl;
    
    return 0;
}