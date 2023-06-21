#include "club.h"

/*
#ifndef CLUB_H
#define CLUB_H

#include <iostream>

struct Member{
    int id;
    std::string email;

};

class Club{
    int num_members_;
    std::unique_ptr<Member[]> members_;

public:
    Club();
    Club(const Club &);
    bool add_member(Member);
    void list_members();
    void save_club(std::string);
    void retrieve_club(std::string);
    Club operator=(Club);
};

#endif //CLUB_H
*/

Club::Club(){
    num_members_ = 0;
    members_ = nullptr;
}

Club::Club(const Club& original){

    std::unique_ptr<Member[]> new_members(new (std::nothrow) Member[num_members_]);

    if(new_members == nullptr){
        std::cout << "Could not allocate memory" << std::endl;
    }
    else{
        for (int i = 0; i < num_members_; i++){
            new_members[i] = members_[i];
        }
    }
    this->num_members_ = original.num_members_;
}

bool Club::add_member(const Member& added_member){
    bool retval = false;
    std::unique_ptr<Member[]> new_member(new (std::nothrow) Member[num_members_ + 1]);
    if(new_member == nullptr){
        retval = false;
    }
    else{
        for (int i = 0; i < num_members_; i++){
            new_member[i] = members_[i];
        }
        new_member[num_members_] = added_member;
        members_ = std::move(new_member);
        num_members_++;
        retval = true;
    }

    return retval;
}

void Club::list_members()const{
    for (int i = 0; i < num_members_; i++){
        std::cout << "ID: " << members_[i].id << ", Email: " << members_[i].email << std::endl;
    }
}

void Club::save_club(std::string filename) const{
    std::ofstream file;
    file.open(filename, std::ios::out);

    if(file.is_open()){
        file << num_members_ << std::endl;

        for (int i = 0; i < num_members_; i++){
            file << members_[i].id << std::endl;
            file << members_[i].email << std::endl;
        }
        file.close();
    }

    else{
        std::cout << "Cannot Open file!" << std::endl;
    }
}

void Club::retrieve_club(std::string filename){
    std::ifstream file;
    file.open(filename, std::ios::in);

    if(file.is_open()){
        int num = 0;
        file >> num;
        this->num_members_ = num;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skipping as much characters as the max size of inputstream or till newline
        std::unique_ptr<Member[]> new_members(new (std::nothrow) Member[num_members_]);


        for (int i = 0; i < num_members_; i++){
            file >> new_members[i].id;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(file, new_members[i].email);
        }

        this->members_ = std::move(new_members);
        file.close();
    }
    else{
        std::cout << "Error opening file!" << std::endl;
    }
}

Club& Club::operator=(const Club& operand){
    this->num_members_ = operand.num_members_;
    std::unique_ptr<Member[]> new_members(new (std::nothrow) Member[num_members_]);

    for (int i = 0; i < num_members_; i++){
        new_members[i] = operand.members_[i];
    }
    this->members_ = std::move(new_members);

    return *this;
}