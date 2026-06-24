#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User{

private:
    int routeID;
    string status;
    bool applied;

public:
    Student()
    {
        routeID = -1;
        status = "Not Applied";
        applied = false;
    }
    Student(string u, string p)
        : User(u,p){
        routeID = -1;
        status = "Not Applied";
        applied = false;
    }
    void applyRoute(int id)
    {
        routeID = id;
        applied = true;
        status = "Pending";
    }
    int getRouteID()
    {
        return routeID;
    }
    bool hasApplied()
    {
        return applied;
    }
    string getStatus()
    {
        return status;
    }
    void setStatus(string s)
    {
        status = s;
    }
    void cancelApplication()
    {
        routeID = -1;
        applied = false;
        status = "Cancelled";
    }

    void menu()
	{
	    cout << "\n====================================";
	    cout << "\n          STUDENT MENU";
	    cout << "\n====================================";
	    cout << "\n1. View Vehicles";
	    cout << "\n2. View Routes";
	    cout << "\n3. Apply For Transport";
	    cout << "\n4. View My Registration";
	    cout << "\n5. Cancel Registration";
	    cout << "\n6. Logout";
	    cout << "\n====================================";
	    cout << "\nEnter Choice : ";
	}
};



#endif