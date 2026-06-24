#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin : public User

{

public:
    Admin() : User("admin","123") {}
    void menu(){

        cout << "\n====================================";
        cout << "\n           ADMIN MENU";
        cout << "\n====================================";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Edit Vehicle";
        cout << "\n3. Remove Vehicle";
        cout << "\n4. Add Route";
        cout << "\n5. Assign Vehicle To Route";
        cout << "\n6. View Applications";
        cout << "\n7. Approve / Reject Requests";
        cout << "\n8. Generate Reports";
        cout << "\n9. Save Data";
        cout << "\n10. Logout";
        cout << "\n====================================";
        cout << "\nEnter Choice : ";

    }

};

#endif







