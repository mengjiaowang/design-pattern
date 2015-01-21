/*  Adapter Pattern
 *
 *  Convert the interface of a class into another interface
 *  clients expect. Adapter lets classes work together that
 *  couldn't otherwise because of incomptible interface.
 *
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

#include <iostream>
using namespace std;

/* defines the domain-specific interface that Client uses */
class Target{
    public:
        Target();
        virtual void request() = 0;
};

/* collaborates with objects conforming to the Target interface */
class Client{
    public:
        Client();
        void function();
};

/* defines an existing interface that needs adapting */
class Adaptee{
    public:
        Adaptee();
        void specialRequest();
};

/* adapts the interface of Adaptee to the Target interface */
class Adapter: public Target, private Adaptee
{
    public:
        Adapter();
        void request();
};

#endif

