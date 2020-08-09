#pragma once

#include <cstdint>
#include <iostream>

enum class CMD_t: uint8_t
{
    STOP           = 0x25, 
    RESET          = 0x40,
    GET_INFO       = 0x50,
    GET_HEALTH     = 0x52,
    GET_SAMPLERATE = 0x59
};

class CMD
{
    protected:
        const CMD_t ID;
        const uint8_t length;

    public:
        CMD(CMD_t id, uint8_t len): ID(id), length(len)
        {}

        virtual void execute() = 0;

        friend class Interface;
};

class SRNR: public CMD
{
    public:
    SRNR(CMD_t id, uint8_t len): CMD(id, len)
    {}

    void execute();
};

class STOP: public SRNR
{
    static STOP * inst;

public:
    STOP(CMD_t id = CMD_t::STOP, uint8_t len = 2): SRNR(id, len)
    {}

    STOP * getInst()
    {
        if (!inst)
            inst = new STOP;
        return inst;
    }
};

class RESET: public SRNR
{
    static RESET * inst;

public:
    RESET(CMD_t id = CMD_t::RESET, uint8_t len = 2): SRNR(id, len)
    {}

    RESET * getInst()
    {
        if (!inst)
            inst = new RESET;
        return inst;
    }
};