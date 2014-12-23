/* Prototype Pattern
 *
 * Specify the kinds of objects to create using a prototypical
 * instance, and create new objects by copying this prototype.
 *
 */

#ifndef PROTOTYPE_H_
#define PROTYTYPE_H_

using namespace std;

/* declares an interface for cloning itself */
class Prototype{
    public:
        Prototype();
        virtual Prototype* clone() = 0;
        int getData();
        void setData(int data);
    private:
        int _data;
};

/* implements an operation for cloning itself */
class ConcretePrototype1: public Prototype{
    public:
        ConcretePrototype1();
        Prototype* clone();
    private:
        int _data;
};

class ConcretePrototype2: public Prototype{
    public:
        ConcretePrototype2();
        Prototype* clone();
    private:
        int _data;
};

/* creates a new object by asking a protytype to clone itself */
class Client{
    public:
        Client();
        void function();
};

#endif
