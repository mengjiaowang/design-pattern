#include "Bridge.h"

int main()
{
    Abstraction *a = new RefinedAbstractionA();
    Abstraction *b = new RefinedAbstractionB();
    a->Operation();
    b->Operation();
    delete a;
    delete b;
    return 0;
}
