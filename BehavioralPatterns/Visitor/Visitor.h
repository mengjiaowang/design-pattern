/*  Visitor Pattern
 *
 *  Represent an operation to be performed on the elements of
 *  an object structure. Visitor lets you define a new operation
 *  without changing the classes of the elements on which it
 *  operates.
 *
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include <iostream>
using namespace std;

class Visitor;
class ConcreteVisitor1;
class ConcreteVisitor2;
class Element;
class ConcreteElementA;
class ConcreteElementB;

/* declares a Visit operation for each class of ConcreteElement in
 * the object structure. The operation's name and signature identifies
 * the class that sends the Visit request to the visitor. That lets
 * the visitor determin the concrete class of the element being visited.
 * Then the visitor can access the element directly through its
 * particular interface.
 */

class Visitor
{
    public:
        virtual void VisitConcreteElementA(ConcreteElementA &a) = 0;
        virtual void VisitConcreteElementB(ConcreteElementB &b) = 0;
    protected:
        Visitor();
};

/* implements each operation declared by Visitor. Each operation implements
 * a fregment of the algorithm defined for the corresponding class
 * of object in the structure. ConcreteVisitor provides the context for the
 * algorithm and stores its local state. This state often accumulates results
 * during the traversal of the structure.
 */

class ConcreteVisitor1: public Visitor
{
    public:
        ConcreteVisitor1();
        void VisitConcreteElementA(ConcreteElementA &a);
        void VisitConcreteElementB(ConcreteElementB &b);
};

class ConcreteVisitor2: public Visitor
{
    public:
        ConcreteVisitor2();
        void VisitConcreteElementA(ConcreteElementA &a);
        void VisitConcreteElementB(ConcreteElementB &b);
};

/* defeins an Accept operation that takes a visitor as an argument. */

class Element
{
    public:
        virtual void Accept(Visitor &v) = 0;
    protected:
        Element();
};

/* implements an Accept operation that takes a visitor as an argument. */

class ConcreteElementA: public Element
{
    public:
        ConcreteElementA();
        void Accept(Visitor &v);
        void OperationA();
};

class ConcreteElementB: public Element
{
    public:
        ConcreteElementB();
        void Accept(Visitor &v);
        void OperationB();
};

/* 1. can enumerate its elements;
 * 2. may provide a high-level interface to allow the visitor to visit its
 *    elements.
 * 3. may either be a composite ora collection such as a list or a set.
 */

class ObjectStructure
{
    public:
        ObjectStructure();
        void Operation();
};

#endif
