#include "CompanyExecutive.h"
using namespace std;

/*
class CompanyExecutive: public ExecutiveEmployee{
    private:
        ExecutiveEmployee *executiveEmployeeDB;

    public:
        static int executiveEmployeeCount;
        CompanyExecutive();
        ~CompanyExecutive();
        bool AddPersonnel(int);
        bool FindPersonnel(const std::string&, ExecutiveEmployee&);
        double CalculateSalary(std::string&);
*/

int CompanyExecutive::executiveEmployeeCount = 0;

CompanyExecutive::CompanyExecutive(){
    name = " ";
    position = " ";
    baseSalary = 0.0;
    stockOptionDividend = 0.0;
    perquisites = 0.0;
    salary = 0.0;
    executiveEmployeeDB = new ExecutiveEmployee[MAX_SIZE];
    executiveEmployeeDB = nullptr;
}

CompanyExecutive::~CompanyExecutive(){
    delete [] executiveEmployeeDB;
}

bool CompanyExecutive::AddPersonnel(int num){
    bool retval = false;
    if(executiveEmployeeCount + num > MAX_SIZE){
        retval = false;
    }
    else{
        ExecutiveEmployee* tempDB = new ExecutiveEmployee[num + executiveEmployeeCount];
        for (int i = 0; i < executiveEmployeeCount; i++){
            tempDB[i].name = executiveEmployeeDB[i].name;
            tempDB[i].position = executiveEmployeeDB[i].position;
            tempDB[i].baseSalary = executiveEmployeeDB[i].baseSalary;
            tempDB[i].stockOptionDividend = executiveEmployeeDB[i].stockOptionDividend;
            tempDB[i].perquisites = executiveEmployeeDB[i].perquisites;
        }
        int totalNum = executiveEmployeeCount + num;

        for (int i = executiveEmployeeCount; i < totalNum; i++){
            cout << "Enter the employee's name: ";
            getline(cin, tempDB[i].name);
            
            cout << "Enter the employee's position: ";
            getline(cin, tempDB[i].position);

            cout << "Enter the employee's base salary: ";
            cin >> tempDB[i].baseSalary;

            cout << "Enter the employee's stock option dividend: ";
            cin >> tempDB[i].stockOptionDividend;

            cout << "Enter the employee's perquisites: ";
            cin >> tempDB[i].perquisites;

            cin.ignore(123, '\n');
            cout << endl;

            executiveEmployeeCount++;

        }
        delete [] executiveEmployeeDB;
        executiveEmployeeDB = tempDB;
        tempDB = nullptr;
        delete [] tempDB;
        retval = true;
    }
    return retval;
}

bool CompanyExecutive::FindPersonnel(const string& name, ExecutiveEmployee& empl){
    bool retval = false;
    for (int i = 0; i < executiveEmployeeCount; i++){
        if (executiveEmployeeDB[i].name == name){
            empl.name = executiveEmployeeDB[i].name;
            empl.position = executiveEmployeeDB[i].position;
            empl.baseSalary = executiveEmployeeDB[i].baseSalary;
            empl.stockOptionDividend = executiveEmployeeDB[i].stockOptionDividend;
            empl.perquisites = executiveEmployeeDB[i].perquisites;
            retval = true;
        }
    }
    return retval;
}

double CompanyExecutive::CalculateSalary(const string& name){
    double salary = 0.0;
    for (int i = 0; i < executiveEmployeeCount; i++){
        if (executiveEmployeeDB[i].name == name){
            salary = executiveEmployeeDB[i].baseSalary + executiveEmployeeDB[i].stockOptionDividend + executiveEmployeeDB[i].perquisites;
        }
    }
    return salary;
}