#include <iostream>
#include "Adapter.h"

Target::Target(){
}

Client::Client(){
}

void Client::function()
{
    Target *t = new Adapter();
    t->request();
    delete t;
}

Adaptee::Adaptee(){
}

void Adaptee::specialRequest()
{
    cout << "Special request from Adaptee" << endl;
}

Adapter::Adapter(){
}

void Adapter::request()
{
    specialRequest();
}

