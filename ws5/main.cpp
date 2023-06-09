#include <iostream>
#include <string>
#include "student.h"
#include "course.h"

int main()
{
    Course course("SEP200", "Object-Oriented Programming");
    Node john("John Smith", 2.9), jane("Jane Doe", 3.5), 
         mohammad("Mohammad Kassim", 3.8), amir("Amir Patel", 3.3);

    course + &john;
    course + &jane;
    course + &mohammad;
    course.display_students();
    
    course + &amir;
    course.display_students();

    return 0;
}