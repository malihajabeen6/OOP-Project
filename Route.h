#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
using namespace std;
class Route{
private:
    int routeID;
    string startPoint;
    string endPoint;
public:
    Route(){
        routeID = 0;
    }
    Route(int id,string s,string e)
    {
        routeID = id;
        startPoint = s;
        endPoint = e;
    }
    int getID()
    {
        return routeID;
    }
    string getStart()
    {
        return startPoint;
    }
    string getEnd()
    {
        return endPoint;
    }
    void display(){
        cout << "\nRoute ID : " << routeID
             << " | " << startPoint
             << " -> " << endPoint;
    }
};

#endif