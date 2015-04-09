#include "Proxy.h"
#include <iostream>
using namespace std;

Subject::Subject()
{
}

RealSubject::RealSubject()
{
}

void RealSubject::Request()
{
    cout << "RealSubject" << endl;
}

Proxy::Proxy(): subject(NULL)
{
}

Proxy::~Proxy()
{
    if(subject != NULL)
    {
        delete subject;
    }
}

void Proxy::Request()
{
    GetRealSubject()->Request();
}

RealSubject* Proxy::GetRealSubject()
{
    if(subject == NULL)
    {
        subject = new RealSubject();
    }
    return subject;
}
