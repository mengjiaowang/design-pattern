#include "TemplateMethod.h"
#include <iostream>
using namespace std;

AbstractClass::AbstractClass()
{
}

void AbstractClass::TemplateMethod()
{
    PrimitiveMethod1();
    PrimitiveMethod2();
}

ConcreteClass::ConcreteClass()
{
}

void ConcreteClass::PrimitiveMethod1()
{
    cout << "ConcreteClass::PrimitiveMethod1()" << endl;
}

void ConcreteClass::PrimitiveMethod2()
{
    cout << "ConcreteClass::PrimitiveMethod2()" << endl;
}

