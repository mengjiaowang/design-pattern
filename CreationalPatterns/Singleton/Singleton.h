/*  Singleton Pattern
 *
 *  Ensure a class only has one instance, and provid
 *  a global point of access to it.
 *
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

/*  defines an instance operation that lets clients access
 *  its unique instance. Instance is a class operation (that
 *  is, a class method in Smalltalk nad a static member function
 *  in C++)
 *
 *  may be responsible for creating its own unique instance
 *
 */

class Singleton{
    public:
        static Singleton* Instance();
    protected:
        Singleton();
    private:
        static Singleton* _instance;
};

#endif
