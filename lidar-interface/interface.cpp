#include "interface.hpp"

#include <iostream>

void Interface::send_data(const CMD * data)
{
    using namespace std;
    cout << "sending data from the interface " << hex << (int)data->ID << endl;
}