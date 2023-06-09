#include "student.h"

/*
class Course;

class Student
{
    std::string name_;
    float gpa_;

    public:
        Student(std::string, float);
        friend class Course;
};
*/

Student::Student(std::string name, float gpa){
    name_ = name;
    gpa_ = gpa;
}