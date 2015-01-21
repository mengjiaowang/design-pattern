#include <iostream>
#include "Bridge.h"
using namespace std;

Abstraction::Abstraction()
{
    imp = new Implementor();
}

Abstraction::~Abstraction()
{
    delete imp;
}

void Abstraction::Operation()
{
    imp->OperationImp();
}

RefinedAbstractionA::RefinedAbstractionA()
{
    imp = new ConcreteImplementorA();
}

RefinedAbstractionA::~RefinedAbstractionA()
{
    delete imp;
}

void RefinedAbstractionA::Operation()
{
    imp->OperationImp();
}

RefinedAbstractionB::RefinedAbstractionB()
{
    imp = new ConcreteImplementorB();
}

RefinedAbstractionB::~RefinedAbstractionB()
{
    delete imp;
}

void RefinedAbstractionB::Operation()
{
    imp->OperationImp();
}

Implementor::Implementor()
{
}

void Implementor::OperationImp()
{
    cout << "Implementor::OperationImp()" << endl;
}

ConcreteImplementorA::ConcreteImplementorA()
{
}

void ConcreteImplementorA::OperationImp()
{
    cout << "ConcreteImplementorA::OperationImp()" << endl;
}

ConcreteImplementorB::ConcreteImplementorB()
{
}

void ConcreteImplementorB::OperationImp()
{
    cout << "ConcreteImplementorB::OperationImp()" << endl;
}
