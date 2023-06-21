#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <fstream>
#include <new>
#include <memory>


struct Member{
    int id;
    std::string email;

};

class Club{
    int num_members_;
    std::unique_ptr<Member[]> members_;

public:
    Club();
    Club(const Club&);
    bool add_member(const Member&);
    void list_members() const;
    void save_club(std::string) const;
    void retrieve_club(std::string);
    Club& operator=(const Club&);
};

#endif //CLUB_H