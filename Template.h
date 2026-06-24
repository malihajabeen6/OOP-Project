#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
using namespace std;

template <class T>
class Printer
{
public:
    static void print(T value)
    {
        cout << value << endl;
    }
};

#endif