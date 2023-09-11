#include "Owner.h"


/*
#ifndef OWNER_H
#define OWNER_H

class Dog;

class Owner
{
    std::string name;
    std::string address;
    std::vector<Dog*> dogs;

    public:
    Owner(std::string name, std::string address) : name{name}, address{address} {}
    void AddDog(Dog& dog);
    std::string GetName() const { return name; }


};
*/
Owner::Owner(const std::string &name, const std::string &address) : name(name), address(address){};

void Owner::AddDog(Dog& dog)
{
    dogs.push_back(&dog);
}

std::string Owner::GetName() const
{
    return name;
}