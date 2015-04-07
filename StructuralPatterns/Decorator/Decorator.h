/* Decorator Pattern
 *
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a fexilable alternative to subclassing
 * for extending functionality.
 */

#ifndef DECORATOR_H_
#define DECORATOR_H_

/* defines the interface for objects that can have responsibilities
 * added to them dynamically.
 */

class Component
{
    public:
        Component();
        virtual void Operation() = 0;
};

/* defines an object to which additional responsibilities can be
 * attached.
 */

class ConcreteComponent: public Component
{
    public:
        ConcreteComponent();
        void Operation();
};

/* maintains a reference to a Component object and defines an
 * interface that conforms to Component's interface.
 */

class Decorator
{
    public:
        Decorator();
        virtual void Operation() = 0;
};

/* adds responsibilities to the component */

class ConcreteDecoratorA: public Decorator
{
    public:
        ConcreteDecoratorA();
        void Operation();
    private:
        void AddedBehaviourA();
};

class ConcreteDecoratorB: public Decorator
{
    public:
        ConcreteDecoratorB();
        void Operation();
    private:
        void AddedBehaviourB();
};


#endif
