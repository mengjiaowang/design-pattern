#include "Builder.h"
int main(){

    // creates Director
    Director dir;

    // ConcreteBuilder1
    ConcreteBuilder1 cb1;
    dir.construct(cb1);

    // ConcreteBuilder2
    ConcreteBuilder2 cb2;
    dir.construct(cb2);

    // exit
    return 0;
}
