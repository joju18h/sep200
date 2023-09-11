#include "Dog.h"
#include "Owner.h"

Dog::Dog(const std::string &name, int age, double price) : name{name}, age{age}, price{price}, owner{nullptr} {}

void Dog::SetOwner(Owner& owner)
{
    this->owner = &owner;
}

Owner *Dog::GetOwner() const
{
    return owner;
}

const std::string& Dog::GetName() const
{
    return name;
}