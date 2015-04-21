/* define an object that ensapsulates how a set of objects interact.
 * Mediator promotes loose coupling by keeping objects from referring
 * to each other explicitly, and it lets you vary their interaction
 * independently.
 */

#ifndef MEDIATOR_H_
#define MEDIATOR_H_

class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

/* defines an interface for communicating with Colleague objects. */
class Mediator
{
    public:
        virtual void Operation() = 0;
        virtual void ColleagueChanged(Colleague *c) = 0;
    protected:
        Mediator();
        virtual void CreateColleague() = 0;
};

/* implements cooperative behavior by coordinating Colleague objects;
 * knows and maintains its colleague.
 */
class ConcreteMediator: public Mediator
{
    public:
        ConcreteMediator();
        ~ConcreteMediator();
        virtual void ColleagueChanged(Colleague *c);
        virtual void Operation();
    protected:
        virtual void CreateColleague();
    private:
        ConcreteColleague1* c1;
        ConcreteColleague2* c2;
};

/* each Colleague class knows its Mediator object;
 * each colleague commnicates with its mediator whenever it would have
 * otherwise communicated with another colleague.
 */
class Colleague
{
    public:
        Colleague(Mediator *m);
        virtual void Changed() = 0;
    protected:
        Mediator * mediator;
};

class ConcreteColleague1: public Colleague
{
    public:
        ConcreteColleague1(Mediator *m);
        virtual void Changed();
};

class ConcreteColleague2: public Colleague
{
    public:
        ConcreteColleague2(Mediator *m);
        virtual void Changed();
};

#endif
