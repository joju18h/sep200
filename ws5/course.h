#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"

class Student;

class Node{
    public:
        Student student_;
        Node* next_;
        Node(std::string, float);
};

struct student_list{
    Node* head;
    Node *tail;
};

class Course{
    std::string code_;
    std::string name_;
    student_list list_;

    public:
        Course(std::string, std::string);
        void display_students();
        friend class Student;
        Course& operator+(Node);
};

#endif //COURSE_H