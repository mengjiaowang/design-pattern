/*  Composite Pattern
 *
 *  Compose objects into tree structures to represent part-whole
 *  hierarchies. Composite lets clients treat individual objects
 *  and compositions of objects uniformly.
 *
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <vector>

/* 1. declares the interface for objects in the composition.
 * 2. implements default behavior for the interface common
 *    to all classes, as appropriate.
 * 3. declares an interface for accessing and managing its
 *    child components.
 * 4. (optional) defines an interface for accessing a component's
 *    parent in the recursive structure, and implements it if
 *    that's appropriate.
 */

class Component
{
    public:
        virtual void Operation();
    protected:
        Component();
};

/* 1. represents leaf objects in the composition. A leaf has no children.
 * 2. defines behavior for primitive objects in the composition.
 */

class Leaf: public Component
{
    public:
        Leaf();
        void Operation();
};

/* 1. defines behavior for components having children.
 * 2. store child components.
 * 3. implements child-related operations in the component interfaces.
 */

class Composite: public Component
{
    public:
        Composite();
        void Operation();
        void Add(Component *c);
        void Remove(int index);
        Component* GetChild(int index);
    private:
        std::vector<Component*> _children;
};

/* manipulates objects in the composition through the Component interface. */

class Client
{
    public:
        Client();
        void function();
};


#endif
