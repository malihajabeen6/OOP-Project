#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
protected:
    string username;
    string password;

public:
    User() {}

    User(string u, string p)
    {
        username = u;
        password = p;
    }

    virtual ~User() {}

    string getUsername() const
    {
        return username;
    }

    string getPassword() const
    {
        return password;
    }

    virtual void menu() = 0;
};

#endif