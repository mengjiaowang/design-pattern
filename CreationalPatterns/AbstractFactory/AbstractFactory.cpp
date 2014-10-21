#include <iostream>
#include "AbstractFactory.h"
using namespace std;

AbstractProductA::AbstractProductA(){
}

AbstractProductB::AbstractProductB(){
}

ProductA1::ProductA1(){
}

void ProductA1::function(){
    cout << "ProductA1" << endl;
}

ProductA2::ProductA2(){
}

void ProductA2::function(){
    cout << "ProductA2" << endl;
}

ProductB1::ProductB1(){
}

void ProductB1::function(){
    cout << "ProductB1" << endl;
}

ProductB2::ProductB2(){
}

void ProductB2::function(){
    cout << "ProductB2" << endl;
}

AbstractFactory::AbstractFactory(){
}

ConcreteFactory1::ConcreteFactory1(){
}

AbstractProductA* ConcreteFactory1::CreateProductA() const{
    return new ProductA1();
}

AbstractProductB* ConcreteFactory1::CreateProductB() const{
    return new ProductB1();
};

ConcreteFactory2::ConcreteFactory2(){
}

AbstractProductA* ConcreteFactory2::CreateProductA() const{
    return new ProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB() const{
    return new ProductB2();
};




