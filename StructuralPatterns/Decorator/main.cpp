#include "Decorator.h"

int main()
{
   ConcreteComponent comp;
   ConcreteDecoratorA a(&comp);
   ConcreteDecoratorB b(&comp);
   comp.Operation();
   a.Operation();
   b.Operation();
   return 0;
}
