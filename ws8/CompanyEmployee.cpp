#include "CompanyEmployee.h"
using namespace std;
/*
class CompanyEmployee{
    private:
        StandardEmployee *standardEmployeeDB;

    public:
        static int standardEmployeeCount;
        CompanyEmployee();
        ~CompanyEmployee();
        bool AddPersonnel(int num);
        bool FindPersonnel(std::string name, StandardEmployee& empl);
        double CalculateSalary(std::string name);
};
*/

int CompanyEmployee::standardEmployeeCount = 0;

CompanyEmployee::CompanyEmployee(){
    name = " ";
    position = " ";
    baseSalary = 0.0;
    profitSharing = 0.0;
    performanceBonus = 0.0;
    salary = 0.0;
    standardEmployeeDB = new StandardEmployee[MAX_SIZE];
    standardEmployeeDB = nullptr;
}

CompanyEmployee::~CompanyEmployee(){
    delete [] standardEmployeeDB;
}

bool CompanyEmployee::AddPersonnel(int num){
    bool retval = false;
    if(standardEmployeeCount + num > MAX_SIZE){
        retval = false;
    }
    else{
        StandardEmployee* tempDB = new StandardEmployee[num + standardEmployeeCount];
        for (int i = 0; i < standardEmployeeCount; i++){
            tempDB[i].name = standardEmployeeDB[i].name;
            tempDB[i].position = standardEmployeeDB[i].position;
            tempDB[i].baseSalary = standardEmployeeDB[i].baseSalary;
            tempDB[i].profitSharing = standardEmployeeDB[i].profitSharing;
            tempDB[i].performanceBonus = standardEmployeeDB[i].performanceBonus;
        }
        int totalNum = standardEmployeeCount + num;

        for (int i = standardEmployeeCount; i < totalNum; i++){
            cout << "Enter the employee's name: ";
            getline(cin, tempDB[i].name);
            
            cout << "Enter the employee's position: ";
            getline(cin, tempDB[i].position);

            cout << "Enter the employee's base salary: ";
            cin >> tempDB[i].baseSalary;

            cout << "Enter the employee's profit sharing: ";
            cin >> tempDB[i].profitSharing;

            cout << "Enter the employee's performance bonus: ";
            cin >> tempDB[i].performanceBonus;


            cin.ignore(123, '\n');
            cout << endl;

            standardEmployeeCount++;
        }
        delete[] standardEmployeeDB;
        standardEmployeeDB = tempDB;
        tempDB = nullptr;
        delete[] tempDB;
        retval = true;
    }
    return retval;
}

bool CompanyEmployee::FindPersonnel(const string &name, StandardEmployee& empl){
    bool retval = false;
    bool found = false;
    for (int i = 0; i < standardEmployeeCount; i++){
        if(standardEmployeeDB[i].name == name){
            empl.name = standardEmployeeDB[i].name;
            empl.position = standardEmployeeDB[i].position;
            empl.baseSalary = standardEmployeeDB[i].baseSalary;
            empl.profitSharing = standardEmployeeDB[i].profitSharing;
            empl.performanceBonus = standardEmployeeDB[i].performanceBonus;
            retval = true;
        }
    }
    return retval;
}

double CompanyEmployee::CalculateSalary(const string &name){
    double salary = 0.0;
    for (int i = 0; i < standardEmployeeCount; i++){
        if(standardEmployeeDB[i].name == name){
            salary = standardEmployeeDB[i].baseSalary + standardEmployeeDB[i].profitSharing + standardEmployeeDB[i].performanceBonus;
        }
    }

    return salary;
}