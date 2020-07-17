#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>

#include <termios.h>
#include <unistd.h>


/*
Give permissions with the following command:
    $ sudo adduser $USER dialout
*/

class Serial
{
public:
    Serial(const std::string& dev_name, const uint32_t br);
    void ll_ser_read();
    void connect_serial();
    void set_tty_options(uint32_t baudrate);
    uint32_t baud_map(uint32_t br);

private:

    struct termios tty_opts;
    int m_ser_handle;
    std::string m_dev_name;
    uint32_t m_br;
};

// Reference: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/