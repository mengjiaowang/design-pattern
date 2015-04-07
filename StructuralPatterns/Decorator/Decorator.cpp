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

Decorator::Decorator(Component* c):component(c)
{
}

void Decorator::Operation()
{
    component->Operation();
}

ConcreteDecoratorA::ConcreteDecoratorA(Component *c)
:Decorator(c)
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

ConcreteDecoratorB::ConcreteDecoratorB(Component *c)
:Decorator(c)
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

