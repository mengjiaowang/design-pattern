/* Define a family of altorithms, encapsulate each one, and make
 * them interchangeable. Stragegy lets the algorithm vary indenpendently
 * from clients that use it.
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

/* declares an interface common to all supported algorithms. Context uses
 * this interface to call the algorithm defined by a ConcreteStrategy.
 */
class Strategy
{
    public:
        Strategy();
        virtual void AlgorithmInterface() = 0;
};

/* implements the algorithm using the Strategy object. */
class ConcreteStrategy1: public Strategy
{
    public:
        ConcreteStrategy1();
        virtual void AlgorithmInterface();
};

class ConcreteStrategy2: public Strategy
{
    public:
        ConcreteStrategy2();
        virtual void AlgorithmInterface();
};

/* is configured with a ConcreteStrategy object;
 * maintains a reference to a Strategy object;
 * may define an interface that lets Strategy access its data.
 */
template <class S>
class Context
{
    public:
        Context(){}
        void ContextInterface(){ strategy.AlgorithmInterface(); }
    private:
        S strategy;
};

#endif
