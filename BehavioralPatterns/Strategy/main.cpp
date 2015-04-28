#include "Strategy.h"

int main()
{
    Context<ConcreteStrategy1> context1;
    context1.ContextInterface();
    Context<ConcreteStrategy2> context2;
    context2.ContextInterface();
    return 0;
}
