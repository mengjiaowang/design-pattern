#include "Strategy.h"
#include <iostream>
using namespace std;

Strategy::Strategy()
{
}

ConcreteStrategy1::ConcreteStrategy1()
{
}

void ConcreteStrategy1::AlgorithmInterface()
{
    cout << "ConcreteStrategy1" << endl;
}

ConcreteStrategy2::ConcreteStrategy2()
{
}

void ConcreteStrategy2::AlgorithmInterface()
{
    cout << "ConcreteStrategy2" << endl;
}

