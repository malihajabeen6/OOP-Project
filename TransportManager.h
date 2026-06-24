#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H
#include <vector>
#include "Student.h"
#include "Admin.h"
#include "Vehicle.h"
#include "Route.h"
#include "Application.h"
#include "Report.h"



class TransportManager{

private:
    vector<Student> students;
    vector<Vehicle> vehicles;
    vector<Route> routes;
    vector<Application> applications;
public:
    TransportManager();
    void registerStudent();
    Student* loginStudent();
    bool loginAdmin();
    void showStudents();
    void showVehicles();
    void showRoutes();
    void applyTransport(Student* s);
    void viewApplications();
    void approveReject();
    void addVehicle();
    void editVehicle();
    void removeVehicle();
    void addRoute();
    void assignVehicle();
    void generateReport();
    void saveData();

};

#endif
