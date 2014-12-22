/*  Factory Method Pattern
 *
 *  Define an interface for creating am object, but let the subclass
 *  decide which class to instantiate. Factory Method lets a class
 *  defer instantiation to subclasses.
 *
 */

#ifndef FACTORY_H_
#define FACTORY_H_

/* define the product ID */

#define CONCRETEPRODUCT1 1
#define CONCRETEPRODUCT2 2

#include <iostream>
using namespace std;

/*  defines the interface of objects the factory method creates */

class Product{
    public:
        Product();
        virtual void function();
};

/*  implements the Product interface */

class ConcreteProduct1: public Product{
    public:
        ConcreteProduct1();
        void function();
};

class ConcreteProduct2: public Product{
    public:
        ConcreteProduct2();
        void function();
};

/* declares the factory method, which returns an object of type
 * Product. Creator may also define a default implementation of
 * the factory method that returns a default ConcreteProduct object.
 *
 * may call the factory method to create a Product object.
 */

class Creator{
    public:
        Creator();
        virtual Product* create(int productID);
};

#endif
