#include <iostream>
#include "cmd.hpp"

using namespace std;

RESET * reset = reset->getInst();
STOP * stop = stop->getInst();

int main()
{
    reset->execute();
    stop->execute();


}