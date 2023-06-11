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

Course Course::operator+ (Node* node){
    if(list_.head == nullptr){
        list_.head = node;
        list_.tail = node;
    }
    else{
        list_.tail->next_ = node;
        list_.tail = node;
    }
    return *this;
}

void Course::display_students(){
    Node *readhead = list_.head;
    while(readhead != nullptr){
        std::cout << "Name: " << readhead->student_.name_ << std::endl;
        std::cout << "GPA: " << readhead->student_.gpa_ << std::endl;
        readhead = readhead->next_;
    }
    std::cout << std::endl;
}