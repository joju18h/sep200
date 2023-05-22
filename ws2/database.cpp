#include <iostream>
#include <new>
#include "database.h"


bool create_list(Data &data, int size){
    bool retval = false;
    data.list_students = new (std::nothrow) Student[size];

    if(data.list_students == nullptr){
        retval = false;
    }
    else{
        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter first name: " << std::endl;
            std::cin >> data.list_students[i].first_name;

            std::cout << "Enter second name: " << std::endl;
            std::cin >> data.list_students[i].second_name;

            std::cout << "Enter the gpa: " << std::endl;
            std::cin >> data.list_students[i].gpa;
            std::cout << std::endl;
        }
        data.size = size;
        retval = true;
    }
    return retval;
}


void list_students(Data &data){

    for (int i = 0; i < data.size; i++){
        std::cout << "First name: " << data.list_students[i].first_name << std::endl;
        std::cout << "Second name: " << data.list_students[i].second_name << std::endl;
        std::cout << "Gpa: " << data.list_students[i].gpa << std::endl << std::endl;
    }
        std::cout << "Number of students: " << data.size << std::endl;
        std::cout << "Total size:" << sizeof(data.size) + sizeof(data.list_students) +
        data.size * (sizeof(data.list_students->first_name) + sizeof(data.list_students->second_name) + sizeof(data.list_students->gpa)) << " bytes" << std::endl << std::endl;

}

void free_memory(Data &data){
    delete[] data.list_students;
}