#include <iostream>
#include "State.h"
using namespace std;

Context::Context()
{
    cout << "Create Context - initial state = state1" << endl;
    _state = ConcreteState1::Instance();
}

void Context::ChangeState(State *s)
{
    _state = s;
}

void Context::Request1()
{
    _state->Handle(this);
}

void Context::Request2()
{
    _state->Handle(this);
}

State::State()
{
}

void State::ChangeState(Context *c, State* s)
{
    c->ChangeState(s);
}

ConcreteState1* ConcreteState1::instance = NULL;

ConcreteState1::ConcreteState1()
{
}

ConcreteState1::~ConcreteState1()
{
    if(instance != NULL) delete instance;
}

ConcreteState1* ConcreteState1::Instance()
{
    if(instance == NULL)
    {
        instance = new ConcreteState1();
    }
    return instance;
}

void ConcreteState1::Handle(Context *c)
{
    cout << "ConcreteState1::Handle() - change to state 2" << endl;
    ChangeState(c, ConcreteState2::Instance());
}

ConcreteState2* ConcreteState2::instance = NULL;

ConcreteState2::ConcreteState2()
{
}

ConcreteState2::~ConcreteState2()
{
    if(instance != NULL) delete instance;
}

ConcreteState2* ConcreteState2::Instance()
{
    if(instance == NULL)
    {
        instance = new ConcreteState2();
    }
    return instance;
}

void ConcreteState2::Handle(Context *c)
{
    cout << "ConcreteState2::Handle() - change to state 1" << endl;
    ChangeState(c, ConcreteState1::Instance());
}

