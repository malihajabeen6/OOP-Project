#include <iostream>
#include "TransportManager.h"

using namespace std;

int main()
{
    TransportManager manager;

    int choice;

    do
    {
        cout << "\n";
        cout << "=====================================================\n";
        cout << "      UNIVERSITY TRANSPORT MANAGEMENT SYSTEM\n";
        cout << "=====================================================\n";
        cout << "1. Register Student\n";
        cout << "2. Student Login\n";
        cout << "3. Admin Login\n";
        cout << "4. View Registered Students\n";
        cout << "5. View Vehicles\n";
        cout << "6. Exit\n";
        cout << "=====================================================\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            manager.registerStudent();
            break;
        }

        case 2:
        {
            Student* student = manager.loginStudent();

            if(student != NULL)
            {
                int studentChoice;

                do
                {
                    student->menu();
                    cin >> studentChoice;

                    switch(studentChoice)
					{
					case 1:
					    manager.showVehicles();
					    break;
					
					case 2:
					    manager.showRoutes();
					    break;
					
					case 3:
					    manager.applyTransport(student);
					    break;
					
					case 4:
					{
					    cout << "\n";
					    cout << "====================================";
					    cout << "\n      REGISTRATION STATUS";
					    cout << "\n====================================";
					
					    if(student->hasApplied())
					    {
					        cout << "\nRoute ID : "
					             << student->getRouteID();
					
					        cout << "\nStatus   : "
					             << student->getStatus();
					    }
					    else
					    {
					        cout << "\nNo Registration Found";
					    }
					
					    cout << "\n====================================\n";
					    break;
					}
					
					case 5:
					{
					    student->cancelApplication();
					
					    cout << "\nRegistration Cancelled\n";
					    break;
					}
					
					case 6:
					{
					    cout << "\nLogged Out Successfully\n";
					    break;
					}
					
					default:
					{
					    cout << "\nInvalid Choice\n";
					}
					}

                }
                while(studentChoice != 6);
            }

            break;
        }

        case 3:
        {
            if(manager.loginAdmin())
            {
                // Admin login hote hi vehicles show honge
                manager.showVehicles();

                int adminChoice;

                do
                {
                    cout << "\n";
                    cout << "====================================\n";
                    cout << "             ADMIN MENU\n";
                    cout << "====================================\n";
                    cout << "1. Add Vehicle\n";
                    cout << "2. Edit Vehicle\n";
                    cout << "3. Remove Vehicle\n";
                    cout << "4. Add Route\n";
                    cout << "5. Assign Vehicle To Route\n";
                    cout << "6. View Applications\n";
                    cout << "7. Approve / Reject Requests\n";
                    cout << "8. Generate Reports\n";
                    cout << "9. Save Data\n";
                    cout << "10. Logout\n";
                    cout << "====================================\n";
                    cout << "Enter Choice : ";

                    cin >> adminChoice;

                    switch(adminChoice)
                    {
                    case 1:
                        manager.addVehicle();
                        break;

                    case 2:
                        manager.editVehicle();
                        break;

                    case 3:
                        manager.removeVehicle();
                        break;

                    case 4:
                        manager.addRoute();
                        break;

                    case 5:
                        manager.assignVehicle();
                        break;

                    case 6:
                        manager.viewApplications();
                        break;

                    case 7:
                        manager.approveReject();
                        break;

                    case 8:
                        manager.generateReport();
                        break;

                    case 9:
                        manager.saveData();
                        break;

                    case 10:
                        cout << "\nAdmin Logged Out\n";
                        break;

                    default:
                        cout << "\nInvalid Choice\n";
                    }

                }
                while(adminChoice != 10);
            }

            break;
        }

        case 4:
        {
            manager.showStudents();
            break;
        }

        case 5:
        {
            manager.showVehicles();
            break;
        }

        case 6:
        {
            cout << "\n";
            cout << "====================================\n";
            cout << " THANK YOU FOR USING THE SYSTEM\n";
            cout << "====================================\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice\n";
        }
        }

    }
    while(choice != 6);

    return 0;
}