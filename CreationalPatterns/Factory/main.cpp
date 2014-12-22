#include <iostream>
#include "Factory.h"
using namespace std;

int main()
{
    Product *p1 = NULL, *p2 = NULL;
    Creator *creator = new Creator();
    p1 = creator->create(CONCRETEPRODUCT1);
    p2 = creator->create(CONCRETEPRODUCT2);

    p1->function();
    p2->function();

    delete p1, p2, creator;
    return 0;
}
