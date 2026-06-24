#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Vehicle
{
private:
    int id;
    string vehicleName;
    int capacity;
    string routeName;

public:
    Vehicle()
    {
        id = 0;
        capacity = 0;
    }

    Vehicle(int i, string n, int c, string r)
    {
        id = i;
        vehicleName = n;
        capacity = c;
        routeName = r;
    }

    int getID()
    {
        return id;
    }

    string getName()
    {
        return vehicleName;
    }

    int getCapacity()
    {
        return capacity;
    }

    string getRoute()
    {
        return routeName;
    }

    void setRoute(string r)
    {
        routeName = r;
    }

    void display()
    {
        cout << "\n--------------------------------";
        cout << "\nVehicle ID : " << id;
        cout << "\nVehicle    : " << vehicleName;
        cout << "\nCapacity   : " << capacity;
        cout << "\nRoute      : " << routeName;
        cout << "\n--------------------------------";
    }
};

#endif