/* without violating encapsulation, capture and externalize an
 * objects's internal state so that the object can be restored
 * to this state later.
 */

#ifndef MEMENTO_H_
#define MEMENTO_H_

class Originator;

/* 1. stores internal state of the Originator object. The memento
 * may store as much or as little of the originator's internal
 * state as necessary at its originator's discretion.
 * 2. protects against access by objects other than the originator.
 * Mementos have effecitively two interfaces. Caretaker sees a
 * narrow interface to the Memento - it can only pass the memento
 * to other objects. Originator, in contrast, sees a wide interface,
 * one that lets it access all the data necessary to restore itself
 * to its preious state. Ideally, only the oringator that produced
 * the memento would be permitted to access the memento's internal
 * state.
 */
class Memento
{
    public:
        // narrow public interface
        virtual ~Memento();
    private:
        friend class Originator;
        Memento();
        void SetState(int state);
        int GetState();
    private:
        int state;
};

/* creates a memento containing a snapshot of its current internal state.
 * uses the memento to restore its internal state.
 */
class Originator
{
    public:
        static Originator* GetInstance();
        void SetMemento(Memento *m);
        void ChangeStatus(int state);
        int GetStatus();
        Memento* CreateMemento();
    protected:
        Originator();
        ~Originator();
    private:
        static Originator * instance;
        static int state;
        Memento *memento;
};

/* is responsible for the memento's safekeeping.
 * never operates on or examines the contents of a memento.
 */
class Caretaker
{
    public:
        Caretaker();
        ~Caretaker();
        void Operation();
        void UndoOperation();
    private:
        Memento *memento;
};


#endif
