/* Observer Pattern
 * Define a one-to-many dependency between objects so that when one
 * object changes state, all its dependents are notified and updated
 * automatically.
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>
using namespace std;

class Observer;

class Subject
{
    public:
        Subject(int value);
        void Attach(Observer *obs);
        void SetValue(int value);
        int GetValue();
        void Notify();
    private:
        vector<Observer*> views;
        int value;
};

class Observer
{
    public:
        Observer(Subject* subject);
        virtual void Update() = 0;
    protected:
        Subject *subject;
};

class ConcreteObserver1: public Observer
{
    public:
        ConcreteObserver1(Subject* subject);
        virtual void Update();
};

class ConcreteObserver2: public Observer
{
    public:
        ConcreteObserver2(Subject* subject);
        virtual void Update();
};

#endif
