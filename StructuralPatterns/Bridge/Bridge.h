/*  Bridge Pattern
 *
 *  Decouple an abstraction from its implementation so that
 *  the two can vary independently.
 *
 */

#ifndef BRIDGE_H_
#define BRIDGE_H_

/*
 * 1. defines the abstraction's interface.
 * 2. maintains a reference to an object of type Implementor.
 */


class Implementor;
class Abstraction
{
    public:
        Abstraction();
        ~Abstraction();
        virtual void Operation();
    protected:
        Implementor* imp;
};

/* extends the interface defined by Abstraction */

class RefinedAbstractionA: public Abstraction
{
    public:
        RefinedAbstractionA();
        ~RefinedAbstractionA();
        void Operation();
};

class RefinedAbstractionB: public Abstraction
{
    public:
        RefinedAbstractionB();
        ~RefinedAbstractionB();
        void Operation();
};

/* defines the interface for implmenetation classes. This interface
 * doesn't have to correspond exactly to Abstraction's interface; in
 * fact the two interface can be quite different. Typically the
 * Implementor interface provides only primitive operations, and
 * Abstraction defeins higher-level operations based on there premitives.
 */

class Implementor
{
    public:
        Implementor();
        virtual void OperationImp();
};

/* implements the Implementor interface and defines its concrete
 * implementation.
 */

class ConcreteImplementorA: public Implementor
{
    public:
        ConcreteImplementorA();
        void OperationImp();
};

class ConcreteImplementorB: public Implementor
{
    public:
        ConcreteImplementorB();
        void OperationImp();
};

#endif
