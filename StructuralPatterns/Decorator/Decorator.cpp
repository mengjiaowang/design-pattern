#include <iostream>
#include "Decorator.h"
using namespace std;

Component::Component()
{
}

ConcreteComponent::ConcreteComponent()
{
}

void ConcreteComponent::Operation()
{
    cout << "ConcreteComponent Operation" << endl;
}

Decorator::Decorator()
{
}

ConcreteDecoratorA::ConcreteDecoratorA()
{
}

void ConcreteDecoratorA::Operation()
{
    cout << "ConcreteDecoratorA Operation" << endl;
    AddedBehaviourA();
}

void ConcreteDecoratorA::AddedBehaviourA()
{
    cout << "ConcreteDecoratorA AddedBehaviourA" << endl;
}

ConcreteDecoratorB::ConcreteDecoratorB()
{
}

void ConcreteDecoratorB::Operation()
{
    cout << "ConcreteDecoratorB Operation" << endl;
    AddedBehaviourB();
}

void ConcreteDecoratorB::AddedBehaviourB()
{
    cout << "ConcreteDecoratorB AddedBehaviourB" << endl;
}

