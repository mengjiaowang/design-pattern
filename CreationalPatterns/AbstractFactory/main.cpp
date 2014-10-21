#include <iostream>
#include "AbstractFactory.h"
using namespace std;

int main()
{
    // create ProductA in Factory1
    ConcreteFactory1 *pFactory1 = new ConcreteFactory1();
    AbstractProductA *pProductA = pFactory1->CreateProductA();
    pProductA->function();

    // create ProductB in Factory2
    ConcreteFactory2 *pFactory2 = new ConcreteFactory2();
    AbstractProductB *pProductB = pFactory2->CreateProductB();
    pProductB->function();

    // release resources
    delete pFactory1;
    delete pProductA;
    delete pFactory2;
    delete pProductB;

    // exit
    return 0;
}
