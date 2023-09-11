#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

struct Crime {
    string m_province{};
    string m_crime{};
    int m_year{};
    int m_cases{};
    size_t m_resolved{};
};

void CrimeUpdates(list<Crime>& crime) {
    // Task 1 - get the total number of cases in Ontario. Name your variable
    // "num".
    std::cout << "CRIME:" << endl;
    int num = std::accumulate(crime.begin(), crime.end(), 0, [](int total, const Crime& c) {
        if (c.m_province == "Ontario") {
            return total + c.m_cases;
        }
        return total + 0;
    });
    std::cout << "The total number of cases in Ontario are " << num << endl << endl;

    // Task 2 - count how many entries have Robbery for the crime. Name your
    // variable "num".
    int count = std::count_if(crime.begin(), crime.end(), [](const Crime& c) {
        return c.m_crime == "Robbery";
    });
    std::cout << "The number of entries with Robbery for the crime are " << count << endl << endl;

    // Task 3 - go through all cases in Nova Scotia and New Brunswick and rename
    // these provinces to "Maritimes"
    std::transform(crime.begin(), crime.end(), crime.begin(), [](Crime& c) {
        if (c.m_province == "Nova Scotia" || c.m_province == "New Brunswick") {
            c.m_province = "Maritimes";
        }
        return c;
    });


    // Task 4 - create a new vector called newCrime. Push all entries of crime onto
    // newCrime, except entries with crime equal to [None].
    // Do not use conventional for-loops.
    vector<Crime> newCrime;
    std::copy_if(crime.begin(), crime.end(),std::back_inserter(newCrime), [](Crime& c) {
        return c.m_crime != "[None]";
    });

    std::cout << "NEWCRIME:" << endl;
    std::for_each(newCrime.begin(), newCrime.end(), [](const Crime& c){
        std::cout << c.m_province << " " << c.m_crime << " " << c.m_year << ""
             << c.m_cases << " " << c.m_resolved << endl;
    });
    std::cout << endl;


    // Task 5 - sort newCrime according to the number of cases (smallest to
    // largest)
    std::sort(newCrime.begin(), newCrime.end(), [](Crime& c1,Crime& c2){return c1.m_cases < c2.m_cases;});
    std::cout <<"Sorted  NewCrime" << endl;
    std::for_each(newCrime.begin(), newCrime.end(), [](const Crime& c){
        std::cout << c.m_province << " " << c.m_crime << " " << c.m_year << ""
             << c.m_cases << " " << c.m_resolved << endl;
    });
}

int main() {
    list<Crime> crimes({
        {"Ontario", "[None]", 2020, 500, 300},
        {"Ontario", "Assault", 2021, 700, 200},
        {"British Columbia", "[None]", 2021, 555, 150},
        {"Manitoba", "Robbery", 2019, 222, 120},
        {"Alberta", "Robbery", 2019, 665, 110},
        {"Alberta", "Extortion", 2019, 234, 104},
        {"Nova Scotia", "Fraud", 2019, 743, 143},
        {"New Brunswick", "Robbery", 2019, 678, 178}
     });

     std::cout << "THE CRIMES:" << endl;
     for (auto& c : crimes) {
         std::cout << c.m_province << " " << c.m_crime << " "
              << c.m_year   <<" "<<c.m_cases<<" "<<c.m_resolved<<endl;
     }
     std::cout<<endl;

     CrimeUpdates(crimes);
     std::cout<<endl;
    std::cout << "THE UPDATED CRIMES:" << endl;
    for (const auto& c : crimes) {
        std::cout << c.m_province << " " << c.m_crime << " " << c.m_year << " " <<c.m_cases<< " " << c.m_resolved << endl;
    }
     return 0;
}
