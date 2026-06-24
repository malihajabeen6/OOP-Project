#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
using namespace std;

class Application{
private:
    string studentName;
    int routeID;
    string status;
public:
    Application()
    {
        routeID = 0;
        status = "Pending";
    }
    Application(string s,int r)
    {
        studentName = s;
        routeID = r;
        status = "Pending";
    }
    string getStudent()
    {
        return studentName;
    }
    int getRouteID()

    {
        return routeID;
    }

    string getStatus()
    {
        return status;
    }
    void setStatus(string s)
    {
        status = s;
    }

};


#endif