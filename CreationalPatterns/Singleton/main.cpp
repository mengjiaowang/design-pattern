#include <iostream>
#include "Singleton.h"
using namespace std;

int main(){
    Singleton *s1 = Singleton::Instance();
    cout << "The value of the Singleton s1 is:" << s1 << endl;
    Singleton *s2 = Singleton::Instance();
    cout << "The value of the Singleton s2 is:" << s2 << endl;
    return 0;
}
