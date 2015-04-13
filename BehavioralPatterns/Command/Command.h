/* Command Pattern
 * Encapsulate a request as an object, thereby letting you
 * parameterize clients with different requests, queue or
 * log requests, and support undoable operation.
 */

#ifndef COMMAND_H_
#define COMMAND_H_

class Receiver1;
class Receiver2;

/* declares an interface for executing an operation */
class Command
{
    public:
        virtual void Execute() = 0;
    protected:
        Command();
};

/* defines a binding between a Receiver object and an action.
 * implements Execute by invocking the corrsponding operation(s)
 * on Receiver.
 */
class ConcreteCommand1: public Command
{
    public:
        ConcreteCommand1(Receiver1* receiver);
        virtual void Execute();
    private:
        Receiver1* receiver;
};

class ConcreteCommand2: public Command
{
    public:
        ConcreteCommand2(Receiver2* receiver);
        virtual void Execute();
    private:
        Receiver2* receiver;
};

/* creates a ConcreteCommand object and sets its receiver. */
class Client
{
    public:
        Client();
        void Operation();
};

/* asks the command to carry out the request */
class Invoker
{
    public:
        Invoker();
        void SetCommand(Command *command);
        void Invoke();
    private:
        Command* command;
};

/* knows how to perform the operations associated with carring out
 * a request. Any class may serve as a Receiver.
 */
class Receiver1
{
    public:
        Receiver1();
        void Action1();
};

class Receiver2
{
    public:
        Receiver2();
        void Action2();
};

#endif
