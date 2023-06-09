#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Course;

class Student
{
    std::string name_;
    float gpa_;

    public:
        Student(std::string, float);
        friend class Course;
};





#endif //STUDENT_H