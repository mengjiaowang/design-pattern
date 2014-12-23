#include <iostream>
#include "Prototype.h"
using namespace std;

Prototype::Prototype(){
    this->_data = 0;
}

int Prototype::getData(){
    return _data;
}

void Prototype::setData(int data){
    _data = data;
}

ConcretePrototype1::ConcretePrototype1(){
    this->_data = 1;
}

Prototype* ConcretePrototype1::clone(){
    Prototype *p = new ConcretePrototype1();
    p->setData(this->_data);
    return p;
}

ConcretePrototype2::ConcretePrototype2(){
    this->_data = 2;
}

Prototype* ConcretePrototype2::clone(){
    Prototype *p = new ConcretePrototype2();
    p->setData(this->_data);
    return p;
}

Client::Client(){
}

void Client::function(){
    ConcretePrototype1 p1;
    ConcretePrototype2 p2;

    Prototype *cp1 = p1.clone();
    Prototype *cp2 = p2.clone();

    cout << cp1->getData() << endl;
    cout << cp2->getData() << endl;

    delete cp1, cp2;
}
