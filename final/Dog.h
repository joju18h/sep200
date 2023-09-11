#ifndef DOG_H
#define DOG_H

#include <string>

class Owner;

class Dog
{
    std::string name;
    int age;
    double price;
    Owner* owner;

    public:
        Dog(const std::string &name, int age, double price);
        void SetOwner(Owner &owner);
        Owner *GetOwner() const;
        const std::string &GetName() const;
};

#endif // DOG_H