#include "ChainOfResponsibility.h"
#include <iostream>
using namespace std;

Handler::Handler()
{
}

void Handler::SetSuccessor(Handler *s)
{
    successor = s;
}

Handler* Handler::GetSuccessor()
{
    return successor;
}

ConcreteHandler1::ConcreteHandler1()
{
}

void ConcreteHandler1::HandleRequest(int requestId)
{
    if(requestId == 1)
    {
        cout << "ConcreteHandler1 handles the request" << endl;
    }
    else
    {
        GetSuccessor()->HandleRequest(requestId);
    }
}

ConcreteHandler2::ConcreteHandler2()
{
}

void ConcreteHandler2::HandleRequest(int requestId)
{
    if(requestId == 2)
    {
        cout << "ConcreteHandler2 handles the request" << endl;
    }
    else
    {
        GetSuccessor()->HandleRequest(requestId);
    }
}

Client::Client()
{
}

void Client::Operation()
{
    ConcreteHandler1 handler1;
    ConcreteHandler2 handler2;
    handler2.SetSuccessor(&handler1);

    handler2.HandleRequest(1);
    handler2.HandleRequest(2);
    handler1.HandleRequest(1);
}
