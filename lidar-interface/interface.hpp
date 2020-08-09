#pragma once

#include "cmd.hpp"

class Interface
{
public:
    static const uint8_t DURATION_MS = 1;
    static void send_data(const CMD * data);
    static void delay(uint8_t wait_factor = 1);
    static void receive_data();
};