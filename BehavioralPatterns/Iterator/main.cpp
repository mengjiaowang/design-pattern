#include "Iterator.h"
#include <iostream>

int main()
{
    ConcreteAggregate<int> a;
    a.PushBack(1);
    a.PushBack(2);
    a.PushBack(3);
    a.PushBack(4);

    Iterator<int> *iter = a.CreateIterator();
    iter->First();
    while(iter->IsDone() == false)
    {
        std::cout << iter->CurrentItem() << std::endl;
        iter->Next();
    }
    return 0;
}
