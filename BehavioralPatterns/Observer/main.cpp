#include "Observer.h"

int main()
{
    int init = 1;
    Subject subject(init);
    ConcreteObserver1 co1(&subject);
    ConcreteObserver2 co2(&subject);
    int newValue = 2;
    subject.SetValue(newValue);
    return 0;
}
