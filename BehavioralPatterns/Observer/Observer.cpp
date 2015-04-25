#include "Observer.h"
#include <iostream>
#include <vector>
using namespace std;

Subject::Subject(int value)
:value(value)
{
}

void Subject::Attach(Observer *obs)
{
    views.push_back(obs);
}

void Subject::SetValue(int value)
{
    this->value = value;
    cout << "Changing the value in Subject, new value = "
         << value << endl;
    this->Notify();
}

int Subject::GetValue()
{
    return this->value;
}

void Subject::Notify()
{
    vector<Observer*>::iterator iter;
    for(iter = views.begin(); iter != views.end(); ++iter)
    {
        (*iter)->Update();
    }
}

Observer::Observer(Subject* subject)
:subject(subject)
{
}

ConcreteObserver1::ConcreteObserver1(Subject* subject)
:Observer(subject)
{
    subject->Attach(this);
}

void ConcreteObserver1::Update()
{
    cout << "ConcreteObserver1 Updated, new value = "
         << subject->GetValue() << endl;
}

ConcreteObserver2::ConcreteObserver2(Subject* subject)
:Observer(subject)
{
    subject->Attach(this);
}

void ConcreteObserver2::Update()
{
    cout << "ConcreteObserver2 Updated, new value = "
         << subject->GetValue() << endl;
}


