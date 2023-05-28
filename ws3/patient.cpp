#include <iostream>
#include <iomanip>
#include "patient.h"

void Patient::display_data(){
    std::cout << "Patient name: " << first_name_ << " " << second_name_ << std::endl;
    std::cout << "Age: " << age_ << " years old" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Height: " << height_ << " m" << std::endl;
    std::cout << "Weight: " << weight_ << " kg" << std::endl;
}

void Patient::edit_data(){
    std::cout << "Enter the Patient's First Name: ";
    std::cin >> first_name_;


    std::cout << "Enter the Patient's Second Name: ";
    std::cin >> second_name_;


    std::cout << "Enter the Patient's Age: ";
    std::cin >> age_;


    std::cout << "Enter the Patient's Height: ";
    std::cin >> height_;


    std::cout << "Enter the Patient's Weight: ";
    std::cin >> weight_;
    std::cout << std::endl;
}

float Patient::calculate_bmi(){
    float bmi = weight_ / (height_ * height_);
    return bmi;
}

void Patient::status_bmi(){

    float bmi = calculate_bmi();
    if(bmi > 30){
        std::cout << "Your BMI status is: obsese" << std::endl;
    }
    else if (bmi > 25){
        std::cout << "Your BMI status is: overweight" << std::endl;
    }
    else if(bmi >18.5){
        std::cout << "Your BMI status is: normal" << std::endl;
    }
    else{
        std::cout << "Your BMI status is: underweight" << std::endl;
    }
}