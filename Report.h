#ifndef REPORT_H
#define REPORT_H
#include <iostream>

using namespace std;

class Report{
public:
    static void header()
    {
        cout << "\n========================================";
        cout << "\n TRANSPORT MANAGEMENT SYSTEM REPORT";
        cout << "\n========================================";
    }
};

#endif