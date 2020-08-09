// #include <cstdint>
// #include <iostream>

#include "cmd.hpp"
#include "interface.hpp"

void SRNR::execute()
{
    // std::cout << "running command" << std::endl;
    // send the command
    // wait for 'x' ms
    Interface::send_data(this);
}

RESET * RESET::inst = nullptr;
STOP * STOP::inst = nullptr;