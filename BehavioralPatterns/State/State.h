/* State Pattern
 * Allow an object to alter its behavior when its internal
 * state changes. The object will appear to change its chass.
 */

#ifndef STATE_H_
#define STATE_H_

class State;

/* defines the interface of interest to clients
 * maintains an instance of a ConcreteState subclass that defines
 * the current state.
 */
class Context
{
    public:
        Context();
        void Request1();
        void Request2();
    private:
        friend class State;
        void ChangeState(State* s);
    private:
        State* _state;
};

/* defines an interface for encapsulating the behavior associated
 * with a particular state of the Context.
 */
class State
{
    public:
        virtual void Handle(Context *c) = 0;
    protected:
        State();
        void ChangeState(Context *c, State* s);
};

/* each subclass implements a behavior associated with a state of
 * the Context.
 */
class ConcreteState1: public State
{
    public:
        virtual void Handle(Context *c);
        static ConcreteState1* Instance();
    protected:
        ConcreteState1();
        ~ConcreteState1();
    private:
        static ConcreteState1* instance;

};

class ConcreteState2: public State
{
    public:
        virtual void Handle(Context *c);
        static ConcreteState2* Instance();
    protected:
        ConcreteState2();
        ~ConcreteState2();
    private:
        static ConcreteState2* instance;

};

#endif
