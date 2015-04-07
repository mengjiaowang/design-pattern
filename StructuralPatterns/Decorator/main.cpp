#include "Decorator.h"

int main()
{
   ConcreteDecoratorA a;
   ConcreteDecoratorB b;
   ConcreteComponent c;
   a.Operation();
   b.Operation();
   c.Operation();
   return 0;
}
