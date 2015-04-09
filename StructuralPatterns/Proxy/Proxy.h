/* Proxy Pattern
 * Provide a surrogate or placeholder for another object to
 * control access to it.
 */

#ifndef PROXY_H_
#define PROXY_H_


/* defines the common interface for RealSubject and Proxy so that
 * a Proxy can be used anywhere a RealSubject is expected. */
class Subject
{
    public:
        Subject();
        virtual void Request() = 0;
};

/* defines the real object that the proxy represents. */
class RealSubject: public Subject
{
    public:
        RealSubject();
        virtual void Request();
};

/* 1. maintains a reference that lets the proxy access the real
 * subject. Proxy may refer to a Subject if the RealSubject and
 * Subject interfaces are the same.
 * 2. provides an interface identical to Subject's so that a proxy
 * can by substituted for the real subject.
 * 3. controls access to the real subject and may be responsible
 * for creating and deleting. */
class Proxy: public Subject
{
    public:
        Proxy();
        ~Proxy();
        virtual void Request();
    protected:
        RealSubject* GetRealSubject();
    private:
        RealSubject* subject;
};

#endif
