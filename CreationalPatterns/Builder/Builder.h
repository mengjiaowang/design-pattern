/*  Builder Pattern
 *  Separate the construction of a complex object from its
 *  representation so that the same construction process
 *  can create different representations
 */

#ifndef BUILDERPATTERN_H_
#define BUILDERPATTERN_H_

/*  specifies an abstract interface for creating parts of
 *  a Product object.
 */
class Builder
{
    public:
        Builder();
        virtual void BuildPart1() = 0;
        virtual void BuildPart2() = 0;
        virtual void BuildPart3() = 0;
        virtual void GetResult() = 0;
};

/*  1. constructs and assembles parts of the product by
 *  implementing the Builder interface
 *  2. defines and keeps track of the representation it
 *  creates
 *  3. provides an interface for retrieving the product.
 */
class ConcreteBuilder1: public Builder
{
    public:
        ConcreteBuilder1();
        void BuildPart1();
        void BuildPart2();
        void BuildPart3();
        void GetResult();
};

class ConcreteBuilder2: public Builder
{
    public:
        ConcreteBuilder2();
        void BuildPart1();
        void BuildPart2();
        void BuildPart3();
        void GetResult();
};

/*  constructs an object using the Builder interface
 */
class Director
{
    public:
        Director();
        void construct(Builder &builder);
};

/*  1. represents the complex object under construction.
 *  ConcreteBuilder builds the product's internal representation
 *  and defines the process bu which it's assembled.
 *  2. includes classes that define the constituent parts,
 *  including interfaces for assembling the parts into the final
 *  result.
 */
class Product
{
    public:
        Product();
};

#endif
