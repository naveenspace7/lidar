#include "interface.hpp"

#include <iostream>

void Interface::send_data(const CMD * data)
{
    using namespace std;
    cout << "sending data from the interface " << hex << (int)data->ID << endl;
}

void Interface::delay(uint8_t wait_factor)
{

}

void Interface::receive_data()
{
    using namespace std;
    cout << "receiving data from the interface" << endl;
}