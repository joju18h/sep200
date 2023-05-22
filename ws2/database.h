#ifndef DATABASE_H_
#define DATABASE_H_

struct Student{
    char first_name[16];
    char second_name[16];
    float gpa;
};

struct Data{
    int size;
    Student *list_students;
};

bool create_list(Data &data, int);
void list_students(Data &data);
void free_memory(Data &data);

#endif //DATABASE_H_