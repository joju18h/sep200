#include "course.h"

/*
class Student;

class Node{
    public:
        Student student_;
        Node* next_;
        Node();
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
        Course operator+(Node*);
};
*/

Node::Node(std::string name, float gpa): student_(name, gpa){
    next_ = nullptr;
}

Course::Course(std::string code, std::string name){
    code_ = code;
    name_ = name;

    list_.head = nullptr;
    list_.tail = nullptr;
}



// void Course::display_students(){
//     while 
// }