#include "Mediator.h"
#include <iostream>
using namespace std;

Mediator::Mediator()
{
}

ConcreteMediator::ConcreteMediator()
:c1(NULL), c2(NULL)
{
}

void ConcreteMediator::ColleagueChanged(Colleague *c)
{
    if(c == c1)
    {
        cout << "Mediator: ConcreteColleague1 Changed!" << endl;
    }
    else if(c == c2)
    {
        cout << "Mediator: ConcreteColleague2 Changed!" << endl;
    }
    else
    {
        cout << "It doesn't belong to this Mediator" << endl;
    }
}

void ConcreteMediator::CreateColleague()
{
    c1 = new ConcreteColleague1(this);
    c2 = new ConcreteColleague2(this);
}

void ConcreteMediator::Operation()
{
    this->CreateColleague();
    c1->Changed();
    c2->Changed();
}

ConcreteMediator::~ConcreteMediator()
{
    if(c1 != NULL) delete c1;
    if(c2 != NULL) delete c2;
}

Colleague::Colleague(Mediator *m)
:mediator(m)
{
}

ConcreteColleague1::ConcreteColleague1(Mediator *m)
: Colleague(m)
{
}

void ConcreteColleague1::Changed()
{
    cout << "Colleague: Colleague1 Changed!" << endl;
    mediator->ColleagueChanged(this);
}

ConcreteColleague2::ConcreteColleague2(Mediator *m)
: Colleague(m)
{
}

void ConcreteColleague2::Changed()
{
    cout << "Colleague: Colleague1 Changed!" << endl;
    mediator->ColleagueChanged(this);
}

