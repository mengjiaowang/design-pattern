/*  Abstract Factory Pattern
 *
 *  Provide an interface for creating families of related or
 *  dependent objects without specifying their concrete classes.
 *
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include <iostream>
using namespace std;

/*  declares an interface for a type of product object
 */
class AbstractProductA{
    public:
        AbstractProductA();
        virtual void function() = 0;
};

class AbstractProductB{
    public:
        AbstractProductB();
        virtual void function() = 0;
};

/*  defines a product object to be created by the
 *  corresponding concrete factory and implements
 *  the AbstractProduct interface
 */
class ProductA1: public AbstractProductA{
    public:
        ProductA1();
        void function();
};

class ProductA2: public AbstractProductA{
    public:
        ProductA2();
        void function();
};

class ProductB1: public AbstractProductB{
    public:
        ProductB1();
        void function();
};

class ProductB2: public AbstractProductB{
    public:
        ProductB2();
        void function();
};

/*  declares an interface for operations that
 *  create abstract product objects
 */
class AbstractFactory{
    public:
        AbstractFactory();
        virtual AbstractProductA* CreateProductA() const = 0;
        virtual AbstractProductB* CreateProductB() const = 0;
};

/*  implements the operations to create concrete product objects
 */
class ConcreteFactory1: public AbstractFactory{
    public:
        ConcreteFactory1();
        AbstractProductA* CreateProductA() const;
        AbstractProductB* CreateProductB() const;
};

class ConcreteFactory2: public AbstractFactory{
    public:
        ConcreteFactory2();
        AbstractProductA* CreateProductA() const;
        AbstractProductB* CreateProductB() const;
};

#endif
