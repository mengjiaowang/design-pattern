/* Template Method Pattern
 * Defines the skeleton of an algorithm in an operation, deferring
 * some steps to subclasses. Template method lets subclases redefine
 * certain steps of an algorithm.
 */

#ifndef TEMPLATE_METHOD_H_
#define TEMPLATE_METHOD_H_

/* defines abstract primitive operations that concrete subclasses
 * define to implement steps of an algorithm.
 * implements a template method defining the skeleton of an
 * algorithm. The template method calls primitive operations as well
 * as operations defined in AbstractClass or those of other objects.
 */
class AbstractClass
{
    public:
        AbstractClass();
        void TemplateMethod();
        virtual void PrimitiveMethod1() = 0;
        virtual void PrimitiveMethod2() = 0;
};

/* implements the primitive operations to carry out subclass-specific
 * steps of the algorithm.
 */
class ConcreteClass: public AbstractClass
{
    public:
        ConcreteClass();
        virtual void PrimitiveMethod1();
        virtual void PrimitiveMethod2();
};

#endif
