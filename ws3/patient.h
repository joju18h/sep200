#ifndef PATIENT_H
#define PATIENT_H

#define SIZE 16

class Patient{
    char first_name_[SIZE];
    char second_name_[SIZE];
    int age_;
    float weight_;
    float height_;

    public:
        void display_data();
        void edit_data();
        float calculate_bmi();
        void status_bmi();
};

#endif //PATIENT_H