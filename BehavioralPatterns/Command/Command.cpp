#include "Command.h"
#include <iostream>
using namespace std;

Command::Command()
{
}

ConcreteCommand1::ConcreteCommand1(Receiver1* receiver)
:receiver(receiver)
{
}

void ConcreteCommand1::Execute()
{
    receiver->Action1();
}

ConcreteCommand2::ConcreteCommand2(Receiver2* receiver)
:receiver(receiver)
{
}

void ConcreteCommand2::Execute()
{
    receiver->Action2();
}

Receiver1::Receiver1()
{
}

void Receiver1::Action1()
{
    cout << "Receiver1::Action1()" << endl;
}

Receiver2::Receiver2()
{
}

void Receiver2::Action2()
{
    cout << "Receiver2::Action2()" << endl;
}

Invoker::Invoker()
{
}

void Invoker::SetCommand(Command* command)
{
    this->command = command;
}

void Invoker::Invoke()
{
    command->Execute();
}

Client::Client()
{
}

void Client::Operation()
{
    Receiver1* rec1 = new Receiver1();
    Receiver2* rec2 = new Receiver2();
    ConcreteCommand1* cmd1 = new ConcreteCommand1(rec1);
    ConcreteCommand2* cmd2 = new ConcreteCommand2(rec2);

    Invoker* inv = new Invoker();
    inv->SetCommand(cmd1);
    inv->Invoke();
    inv->SetCommand(cmd2);
    inv->Invoke();

    delete rec1;
    delete rec2;
    delete cmd1;
    delete cmd2;
    delete inv;
}

