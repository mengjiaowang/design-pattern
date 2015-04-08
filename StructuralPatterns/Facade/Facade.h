/* Facade Pattern
 * Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher-level interface that makes the subsystem
 * easier to use.
 */

#ifndef FACADE_H_
#define FACADE_H_

/* knows which subsystem classes are responsible for a request.
 * delegates client requests to appropriate subsystem objects.
 */

class Facade
{
    public:
        static Facade* Instance();
        void Operation();
    protected:
        Facade();
    private:
        static Facade* instance;
};

/* implement subsystem functionality
 * handle work assigned by the Facade object
 * have no knowledge of the facade; that is, they keep no references
 * to it.
 */

class Subsystem1
{
    public:
        Subsystem1();
        void Operation();
};

class Subsystem2
{
    public:
        Subsystem2();
        void Operation();
};

#endif
