#include "Facade.h"
#include <iostream>
using namespace std;

Facade* Facade::instance = NULL;

Facade::Facade()
{
}

Facade* Facade::Instance()
{
    if(instance == NULL)
    {
        instance = new Facade();
    }
    return instance;
}

void Facade::Operation()
{
    Subsystem1 sub1;
    Subsystem2 sub2;
    sub1.Operation();
    sub2.Operation();
}

Subsystem1::Subsystem1()
{
}

void Subsystem1::Operation()
{
    cout << "Subsystem1 Operation" << endl;
}

Subsystem2::Subsystem2()
{
}

void Subsystem2::Operation()
{
    cout << "Subsystem2 Operation" << endl;
}
