#include "Facade.h"

int main()
{
    Facade* instance = Facade::Instance();
    instance->Operation();
    return 0;
}
