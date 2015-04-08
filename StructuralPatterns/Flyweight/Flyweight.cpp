#include "Flyweight.h"
#include <map>
#include <iostream>
using namespace std;

Flyweight::Flyweight(int key)
:key(key)
{
}

ConcreteFlyweight::ConcreteFlyweight(int key)
:Flyweight(key)
{
}

void ConcreteFlyweight::Operation(int extrinsicState)
{
    cout << "extrinsicState:" << extrinsicState << endl;
}

UnsharedConcreteFlyweight::UnsharedConcreteFlyweight(int key)
:Flyweight(key)
{
}

void UnsharedConcreteFlyweight::Operation(int extrinsicState)
{
    cout << "extrinsicState:" << extrinsicState << endl;
}

ConcreteFlyweightFactory::ConcreteFlyweightFactory()
{
}

ConcreteFlyweight* ConcreteFlyweightFactory::GetFlyweight(int key)
{
    std::map<int, ConcreteFlyweight>::iterator iter;
    iter = flyweights.find(key);
    ConcreteFlyweight *ptr = NULL;
    if(iter == flyweights.end())
    {
        ptr = new ConcreteFlyweight(key);
        flyweights.insert(std::pair<int, ConcreteFlyweight>(key, *ptr));
    }
    else
    {
        ptr = &iter->second;
    }
    return ptr;
}

Client::Client()
{
}

void Client::Operation()
{
    int key1 = 1, key2 = 2;
    int state1 = 1, state2 = 2, state3 = 3;
    ConcreteFlyweightFactory factory;

    ConcreteFlyweight* f1 = factory.GetFlyweight(key1);
    ConcreteFlyweight* f2 = factory.GetFlyweight(key1);
    ConcreteFlyweight* f3 = factory.GetFlyweight(key2);

    f1->Operation(state1);
    f2->Operation(state2);
    f3->Operation(state3);

    return;
}
