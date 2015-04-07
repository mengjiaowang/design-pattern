/* Iterator Pattern
 *
 * Provide a way to access the elements of an aggregate object
 * sequentially without exposing its underlying representation.
 *
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class IndexOutOfBoundException: public exception
{
    virtual const char* what() const throw()
    {
        return "index out of bound happened";
    }

}IndexOutOfBoundException;

template<class Item>
class ConcreteIterator;

template<class Item>
class Aggregate;

template<class Item>
class ConcreteAggregate;

/* defines an interface for accessing and traversing elements.
*/
template<class Item>
class Iterator
{
    public:
        Iterator(){};
        virtual ~Iterator(){};
        virtual void First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() const = 0;
        virtual void PushBack(Item item) = 0;
        virtual Item CurrentItem() const = 0;
};

/* implements the Iterator interface
 * keeps track of the current position in the traversal of the
 * aggerate.
 */
template<class Item>
class ConcreteIterator: public Iterator<Item>
{
    public:
        ConcreteIterator(Aggregate<Item>* a): current(0), container(a)
        {
        }
        ~ConcreteIterator(){};
        void First()
        {
            current = 0;
        }
        void Next()
        {
            current ++;
        }
        bool IsDone() const
        {
            return current >= container->count();
        }
        void PushBack(Item item)
        {
            container->PushBack(item);
        }
        Item CurrentItem() const
        {
            if(!IsDone())
            {
                return container->get(current);
            }
            else
            {
                throw IndexOutOfBoundException;
            }
        }
    private:
        size_t current;
        Aggregate<Item> *container;
};

/* defines an interface for creating an Iterator object. */
template<class Item>
class Aggregate
{
    public:
        Aggregate(){};
        ~Aggregate(){};
        virtual Iterator<Item>* CreateIterator() = 0;
        virtual Item get(size_t index) const
        {
            if(index < container.size())
            {
                return container[index];
            }
            else
            {
                throw IndexOutOfBoundException;
            }
        }
        virtual size_t count() const
        {
            return container.size();
        }
        virtual void PushBack(Item item)
        {
            container.push_back(item);
        }
    private:
        vector<Item> container;
};

/* implements the Iterator creation interface to return an
 * instance of the proper ConcreteInterator
 */
template<class Item>
class ConcreteAggregate: public Aggregate<Item>
{
    public:
        ConcreteAggregate():iter(NULL){};
        ~ConcreteAggregate()
        {
            if(iter != NULL) delete iter;
        }
        virtual Iterator<Item>* CreateIterator()
        {
            iter = new ConcreteIterator<Item>(this);
            return iter;
        }
    private:
        Iterator<Item> * iter;
};

#endif
