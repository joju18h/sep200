//CompanyExecutive.h class definition, George Paul Robert, 117928226
#ifndef COMPANYEXECUTIVE_H
#define COMPANYEXECUTIVE_H

#include "CompanyCommon.h"

class CompanyExecutive: public ExecutiveEmployee{
    private:
        ExecutiveEmployee *executiveEmployeeDB;

    public:
        static int executiveEmployeeCount;
        CompanyExecutive();
        ~CompanyExecutive();
        bool AddPersonnel(int);
        bool FindPersonnel(const std::string&, ExecutiveEmployee&);
        double CalculateSalary(const std::string&);
};
#endif // COMPANYEXECUTIVE_H