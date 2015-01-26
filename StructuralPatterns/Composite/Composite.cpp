#include <vector>
#include <iostream>
#include "Composite.h"
using namespace std;

Component::Component()
{
}

void Component::Operation()
{
    cout << "Component::Operation()" << endl;
}

Leaf::Leaf()
{
}

void Leaf::Operation()
{
    cout << "Leaf::Operation()" << endl;
}

Composite::Composite()
{
}

void Composite::Operation()
{
    cout << "Composite::Operation" << endl;
    vector<Component*>::iterator iter = _children.begin();
    for(iter; iter != _children.end(); iter++)
    {
        (*(iter))->Operation();
    }
}

void Composite::Add(Component *c)
{
    _children.push_back(c);
}

void Composite::Remove(int index)
{
    vector<Component*>::iterator iter;
    iter = _children.begin() + index;
    _children.erase(iter);
}

Component* Composite::GetChild(int index)
{
    vector<Component*>::iterator iter;
    iter = _children.begin() + index;
    return *iter;
}

Client::Client()
{
}

void Client::function()
{
    Leaf l1, l2, l3, l4;
    Composite c1, c2;
    c1.Add(&l1);
    c1.Add(&l2);
    c1.Add(&c2);
    c2.Add(&l3);
    c2.Add(&l4);
    c1.Operation();
}
