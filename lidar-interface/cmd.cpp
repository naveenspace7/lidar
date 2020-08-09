#include "cmd.hpp"
#include "interface.hpp"

RESET * RESET::inst = nullptr;
STOP * STOP::inst = nullptr;
GET_HEALTH * GET_HEALTH::inst = nullptr;
GET_INFO * GET_INFO::inst = nullptr;
GET_SAMPLERATE * GET_SAMPLERATE::inst = nullptr;
SCAN * SCAN::inst = nullptr;

void SRNR::execute()
{
    Interface::send_data(this);
    Interface::delay(2);
}

void SRSR::execute()
{
    Interface::send_data(this);
    Interface::delay();
    Interface::receive_data();
}

void SCAN::data_rx()
{
    // keep receiving the data and keep filling the buffer 
}

void SCAN::execute()
{
    Interface::send_data(this);
    Interface::receive_data();

    // if valid response is received
    if (false)
    {
        receiver_thread = std::thread(data_rx);
        m_scan_active = true;
    }
}

SCAN::~SCAN()
{
    if (m_scan_active)
        receiver_thread.join();
}

std::optional<int> SCAN::get_next_data()
{
    // TODO: read the buffer and return the element
    return 0;
}