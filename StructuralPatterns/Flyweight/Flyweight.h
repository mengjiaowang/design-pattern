/* Flyweight Pattern
 * User sharing to support large numbers of fine-grained
 * objects efficiently.
 */

#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include <map>

/* declares an interface through which flyweights can
 * receive and act on extrinsic state. */
class Flyweight
{
    public:
        Flyweight(int key);
        virtual void Operation(int extrinsicState) = 0;
    private:
        int key;
};

/* implements the Flyweight interface and adds storage for
 * intrinsic state, if any. A ConcreteFlyweight object must
 * be sharable. Any state it stores must be intrinsic; that
 * is, it must be independent of the ConcreteFlyweight
 * objects's context. */
class ConcreteFlyweight: public Flyweight
{
    public:
        ConcreteFlyweight(int key);
        void Operation(int extrinsicState);
};

/* not all Flyweight subclasses need to be shared. The Flyweight
 * interface enables sharing; it doesn't enforce it. It's common
 * for UnsharedConcreteFlyweight objects to have ConcreteFlyweight
 * objects as children at some level in the flyweight object
 * structure (as the Row and Column classes have). */
class UnsharedConcreteFlyweight: public Flyweight
{
    public:
        UnsharedConcreteFlyweight(int key);
        void Operation(int extrinsicState);
};

/* creates and manages flyweight objects;
 * ensures that flyweights are shared properly. When a client
 * requests a flyweight, the FlyweightFactory object supplies an
 * existing instance or creates one, if none exists. */
class ConcreteFlyweightFactory
{
    public:
        ConcreteFlyweightFactory();
        ConcreteFlyweight* GetFlyweight(int key);
    private:
        std::map<int, ConcreteFlyweight> flyweights;
};

/* maintains a reference to flyweight(s);
 * computes or store the extrinsic state of flyweight(s). */
class Client
{
    public:
        Client();
        void Operation();
};

#endif
