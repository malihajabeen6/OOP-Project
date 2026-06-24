#include "TransportManager.h"
#include <fstream>
using namespace std;


TransportManager::TransportManager(){

    vehicles.push_back(
        Vehicle(1,"Bus A",50,"University -> City")
    );
    vehicles.push_back(
        Vehicle( 2,"Van B",25,"Hostel -> University" )
    );

    routes.push_back(
        Route(1,"University", "City")

    );
    routes.push_back(

        Route(2,"Hostel","University")
    );

}

void TransportManager::registerStudent(){
    string username;
    string password;
    
    cout << "\nEnter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;
    students.push_back(
        Student( username,password )

    );
    
    cout << "\n====================================";
    cout << "\nStudent Registered Successfully";
    cout << "\n====================================\n";

}


Student* TransportManager::loginStudent(){

    string username;
    string password;

    cout << "\nUsername : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    for(int i=0;i<students.size();i++)
    {

        if(
            students[i].getUsername()==username &&
            students[i].getPassword()==password
          )
        {

            cout << "\nLogin Successful\n";
            return &students[i];

        }

    }
    cout << "\nInvalid Credentials\n";
    return NULL;
}


bool TransportManager::loginAdmin(){

    string username;
    string password;

    cout << "\nAdmin Username : ";
    cin >> username;
    cout << "Admin Password : ";
    cin >> password;
    if(

        username=="admin" && password=="123"

      )
    {

        cout << "\nAdmin Login Successful\n";
        return true;

    }
    cout << "\nWrong Admin Credentials\n";
    return false;

}

void TransportManager::showStudents()
{

    cout << "\n====================================";
    cout << "\n      REGISTERED STUDENTS";
    cout << "\n====================================";
    if(students.size()==0)
    {

        cout << "\nNo Students Registered\n";
        return;
    }

    for(int i=0;i<students.size();i++)

    {

        cout << "\n"<< i+1<< ". "<< students[i].getUsername();

    }
    cout << endl;

}

void TransportManager::showVehicles()

{
    cout << "\n====================================";
    cout << "\n       AVAILABLE VEHICLES";
    cout << "\n====================================";

    for(int i=0;i<vehicles.size();i++)
    {

        vehicles[i].display();
    }

    cout << endl;

}

void TransportManager::showRoutes()
{
    cout << "\n====================================";
    cout << "\n      ROUTES WITH VEHICLES";
    cout << "\n====================================";

    cout << "\nRoute ID : 1";
    cout << "\nVehicle  : Bus A";
    cout << "\nRoute    : University -> City";
    cout << "\n--------------------------------";

    cout << "\nRoute ID : 2";
    cout << "\nVehicle  : Van B";
    cout << "\nRoute    : Hostel -> University";
    cout << "\n--------------------------------";

    cout << endl;
}
void TransportManager::applyTransport(Student* s)
{
    int routeID;

    if(s->hasApplied())
    {
        cout << "\nYou already submitted request.\n";
        return;
    }

    showVehicles();

    cout << "\n====================================";
    cout << "\n       AVAILABLE ROUTES";
    cout << "\n====================================";

    showRoutes();

    cout << "\nEnter Route ID : ";
    cin >> routeID;

    s->applyRoute(routeID);

    applications.push_back(
        Application(
            s->getUsername(),
            routeID
        )
    );

    cout << "\n====================================";
    cout << "\nApplication Submitted Successfully";
    cout << "\nStatus : Pending";
    cout << "\n====================================";
}


// View Applications

void TransportManager::viewApplications()

{

    cout << "\n====================================";

    cout << "\n       STUDENT REQUESTS";

    cout << "\n====================================";



    if(applications.size()==0)

    {

        cout << "\nNo Applications Found\n";

        return;

    }



    for(int i=0;i<applications.size();i++)

    {

        cout << "\nApplication # "

             << i+1;



        cout << "\nStudent : "

             << applications[i].getStudent();



        cout << "\nRoute ID : "

             << applications[i].getRouteID();



        cout << "\nStatus : "

             << applications[i].getStatus();



        cout << "\n-----------------------";

    }

}



// Approve / Reject

void TransportManager::approveReject()

{

    if(applications.size()==0)

    {

        cout << "\nNo Applications Available\n";

        return;

    }



    viewApplications();
    int appNo;

    int choice;



    cout << "\nApplication Number : ";

    cin >> appNo;



    appNo--;

    if(

        appNo < 0 ||

        appNo >= applications.size()

      )

    {

        cout << "\nInvalid Application\n";

        return;

    }


    cout << "\n1. Approve";

    cout << "\n2. Reject";

    cout << "\nChoice : ";

    cin >> choice;



    string studentName =applications[appNo].getStudent();



    for(int i=0;i<students.size();i++)

    {

        if( students[i].getUsername()== studentName)

        {

            if(choice==1)

            {

                applications[appNo].setStatus("Approved");

                students[i].setStatus("Approved");
                cout << "\nRequest Approved\n";

            }

            else

            {

                applications[appNo].setStatus("Rejected");
                students[i].setStatus("Rejected");
                cout << "\nRequest Rejected\n";

            }

        }

    }

}



// Add Vehicle

void TransportManager::addVehicle()

{

    int id;

    int cap;



    string name;

    string route;



    cout << "\nVehicle ID : ";

    cin >> id;
	for(int i=0; i<vehicles.size(); i++)
	{
	    if(vehicles[i].getID() == id)
	    {
	        cout << "\nVehicle ID Already Exists\n";
	        return;
	    }
	}


    cin.ignore();



    cout << "Vehicle Name : ";

    getline(cin,name);



    cout << "Capacity : ";

    cin >> cap;



    cin.ignore();



    cout << "Route : ";

    getline(cin,route);



    vehicles.push_back(

        Vehicle( id, name,cap,route)

    );



    cout << "\nVehicle Added Successfully\n";

}



// Edit Vehicle

void TransportManager::editVehicle()

{

    int id;



    cout << "\nEnter Vehicle ID : ";

    cin >> id;



    cout << "\nFeature Coming Soon\n";

}



// Remove Vehicle

void TransportManager::removeVehicle()

{

    int id;



    cout << "\nVehicle ID : ";

    cin >> id;



    for(int i=0;i<vehicles.size();i++)

    {

        if(

            vehicles[i].getID() ==id )

        {

            vehicles.erase(vehicles.begin()+i );



            cout << "\nVehicle Removed\n";

            return;

        }

    }



    cout << "\nVehicle Not Found\n";

}



// Add Route

void TransportManager::addRoute()

{

    int id;



    string start;

    string end;



    cout << "\nRoute ID : ";

    cin >> id;



    cin.ignore();



    cout << "Start Point : ";

    getline(cin,start);



    cout << "End Point : ";

    getline(cin,end);



    routes.push_back(

        Route(id, start, end )

    );



    cout << "\nRoute Added Successfully\n";

}



// Assign Vehicle

void TransportManager::assignVehicle()

{
    cout << "\nVehicle Assigned Successfully\n";
}

void TransportManager::generateReport()

{

    Report::header();

    cout << "\nTotal Students : "<< students.size();

    cout << "\nTotal Vehicles : "<< vehicles.size();
    cout << "\nTotal Routes : "<< routes.size();

    cout << "\nTotal Applications : "<< applications.size();
    cout << "\n====================================\n";

}

void TransportManager::saveData()

{

    ofstream file("students.txt" );

    for(int i=0;i<students.size();i++)

    {

        file<< students[i].getUsername()<< " " << students[i].getPassword()<< " "<< students[i].getStatus()<< endl;

    }

    file.close();

    cout << "\nData Saved Successfully\n";

}
