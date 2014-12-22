#include <iostream>
#include "Factory.h"
using namespace std;

Product::Product(){
}

void Product::function(){
    cout << "Product" << endl;
}

ConcreteProduct1::ConcreteProduct1(){
}

void ConcreteProduct1::function(){
    cout << "ConcreteProduct1" << endl;
}

ConcreteProduct2::ConcreteProduct2(){
}

void ConcreteProduct2::function(){
    cout << "ConcreteProduct2" << endl;
}

Creator::Creator(){
}

Product* Creator::create(int id){
    if(id == CONCRETEPRODUCT1)
        return new ConcreteProduct1();
    if(id == CONCRETEPRODUCT2)
        return new ConcreteProduct2();
    return NULL;
}
