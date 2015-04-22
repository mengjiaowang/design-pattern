#include <iostream>
#include "Memento.h"
using namespace std;

Memento::~Memento()
{
}

Memento::Memento()
{
}

void Memento::SetState(int state)
{
    this->state = state;
}

int Memento::GetState()
{
    return this->state;
}

Originator::Originator()
{
}

Originator::~Originator()
{
//    if(instance != NULL) delete instance;
}

Originator* Originator::instance = NULL;
int Originator::state = 0;

Originator* Originator::GetInstance()
{
    if(instance == NULL)
    {
        instance = new Originator();
    }
    return instance;
}

void Originator::SetMemento(Memento *m)
{
    state = memento->GetState();
}

void Originator::ChangeStatus(int state)
{
    this->state = state;
}

int Originator::GetStatus()
{
    return state;
}

Memento* Originator::CreateMemento()
{
    this->memento = new Memento();
    this->memento->SetState(this->state);
    return memento;
}

Caretaker::Caretaker()
{
}

Caretaker::~Caretaker()
{
    if(memento != NULL) delete memento;
}

void Caretaker::Operation()
{
    Originator *ori = Originator::GetInstance();
    memento = ori->CreateMemento();
    ori->ChangeStatus(10);
    cout << "Changed the status to: 10" << endl;
}

void Caretaker::UndoOperation()
{
    Originator *ori = Originator::GetInstance();
    ori->SetMemento(memento);
    cout << "Undo the change! the status now is: " << ori->GetStatus() << endl;
}
