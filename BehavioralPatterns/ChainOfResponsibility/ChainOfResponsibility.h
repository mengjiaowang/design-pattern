/* ChainOfResponsibility Pattern
 * Avoid coupling the sender of a request to its
 * receiver by giving more than one object a change
 * to handle the request. Chain the receiving objects
 * and pass the request along the chain until an
 * object handles it.
 */

#ifndef CHAIN_OF_RESPONSIBILITY_H_
#define CHAIN_OF_RESPONSIBILITY_H_

/* defines an interface for handling requests;
 * implements the successor link;
 */
class Handler
{
    public:
        Handler();
        virtual void HandleRequest(int requestId) = 0;
        void SetSuccessor(Handler *s);
        Handler* GetSuccessor();
    private:
        Handler *successor;
};

/* handles requests it is responsible for;
 * can access its successor;
 * if the ConcreteHandler can handle the request, it
 * does so; otherwise it forwards the request to its
 * successor.
 */
class ConcreteHandler1: public Handler
{
    public:
        ConcreteHandler1();
        virtual void HandleRequest(int requestId);
};

class ConcreteHandler2: public Handler
{
    public:
        ConcreteHandler2();
        virtual void HandleRequest(int requestId);
};

/* initiates the request to a Concretehander object on
 * the chain.
 */
class Client
{
    public:
        Client();
        void Operation();
};

#endif
