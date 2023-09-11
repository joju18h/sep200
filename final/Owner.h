#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <vector>
#include "Dog.h"

class Dog;

class Owner
{
    std::string name;
    std::string address;
    std::vector<Dog*> dogs;

    public:
        Owner(const std::string &name, const std::string &address);
        void AddDog(Dog &dog);
        std::string GetName() const;
};
#endif // OWNER_H
