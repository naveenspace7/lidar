#pragma once

#include <cstdint>
#include <iostream>

#include <optional>
#include <thread>

enum class STAT: int8_t
{
    SUCCESS = 0,
    FAILED  = -1
};

enum class CMD_t: uint8_t
{
    STOP           = 0x25, 
    RESET          = 0x40,
    GET_INFO       = 0x50,
    GET_HEALTH     = 0x52,
    GET_SAMPLERATE = 0x59,
    SCAN           = 0x20
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

class SRSR: public CMD
{
public:
    SRSR(CMD_t id, uint8_t len): CMD(id, len)
    {}

    void execute();
};

class GET_INFO: public SRSR
{
    static GET_INFO * inst;

public:
    GET_INFO(CMD_t id = CMD_t::GET_INFO, uint8_t len = 2): SRSR(id, len)
    {}

    GET_INFO * getInst()
    {
        if(!inst) inst = new GET_INFO;
        return inst;
    }
};

class GET_HEALTH: public SRSR
{
    static GET_HEALTH * inst;
public:
    GET_HEALTH(CMD_t id = CMD_t::GET_HEALTH, uint8_t len = 2): SRSR(id, len)
    {}

    GET_HEALTH * getInst()
    {
        if (!inst) inst = new GET_HEALTH;
        return inst;
    }
};

class GET_SAMPLERATE: public SRSR
{
    static GET_SAMPLERATE * inst;
public:
    GET_SAMPLERATE(CMD_t id = CMD_t::GET_SAMPLERATE, uint8_t len = 2): SRSR(id, len)
    {}

    GET_SAMPLERATE * getInst()
    {
        if (!inst) inst = new GET_SAMPLERATE;
        return inst;
    }
};

class SRMR: public CMD
{
public:
    SRMR(CMD_t id, uint8_t len): CMD(id, len)
    {}
};

class SCAN: public SRMR
{
    static SCAN * inst;

    int data[100]; // temp holder

    std::thread receiver_thread;

    bool m_scan_active;

public:

    SCAN(CMD_t id = CMD_t::SCAN, uint8_t len = 2): SRMR(id, len), 
                                                   m_scan_active {false}
    {}

    SCAN * getInst()
    {
        if (!inst) inst = new SCAN;
        return inst;
    }

    static void data_rx();

    void execute();

    std::optional<int> get_next_data();


    ~SCAN();
};