#include <iostream>
#include <vector>
#include "Visitor.h"
using namespace std;

Visitor::Visitor()
{
}

ConcreteVisitor1::ConcreteVisitor1()
{
}

void ConcreteVisitor1::VisitConcreteElementA(ConcreteElementA &a)
{
    a.OperationA();
}

void ConcreteVisitor1::VisitConcreteElementB(ConcreteElementB &b)
{
    b.OperationB();
}

ConcreteVisitor2::ConcreteVisitor2()
{
}

void ConcreteVisitor2::VisitConcreteElementA(ConcreteElementA &a)
{
    a.OperationA();
}

void ConcreteVisitor2::VisitConcreteElementB(ConcreteElementB &b)
{
    b.OperationB();
}

Element::Element()
{
}

ConcreteElementA::ConcreteElementA()
{
}

void ConcreteElementA::Accept(Visitor &v)
{
    v.VisitConcreteElementA(*this);
}

void ConcreteElementA::OperationA()
{
    cout << "ConcreteElementA::OperationA" << endl;
}

ConcreteElementB::ConcreteElementB()
{
}

void ConcreteElementB::Accept(Visitor &v)
{
    v.VisitConcreteElementB(*this);
}

void ConcreteElementB::OperationB()
{
    cout << "ConcreteElementB::OperationB" << endl;
}

ObjectStructure::ObjectStructure()
{
}

void ObjectStructure::Operation()
{
    std::vector<Element*> elements;
    ConcreteElementA ea;
    ConcreteElementB eb;
    elements.push_back(&ea);
    elements.push_back(&eb);

    ConcreteVisitor1 v1;
    ConcreteVisitor2 v2;

    for(int i = 0; i != elements.size(); ++i)
    {
        (elements[i])->Accept(v1);
    }

    for(int i = 0; i != elements.size(); ++i)
    {
        (elements[i])->Accept(v2);
    }
}

