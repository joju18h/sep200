//CompanyEmployee class header file, George Paul Robert, 117928226
#ifndef COMPANYEMPLOYEE_H
#define COMPANYEMPLOYEE_H

#include "CompanyCommon.h"

class CompanyEmployee: public StandardEmployee{
    private:
        StandardEmployee *standardEmployeeDB;

    public:
        static int standardEmployeeCount;
        CompanyEmployee();
        ~CompanyEmployee();
        bool AddPersonnel(int);
        bool FindPersonnel(const std::string&, StandardEmployee&);
        double CalculateSalary(const std::string&);
};



#endif // COMPANYEMPLOYEE_H