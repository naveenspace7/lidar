#include "serial.hpp"
#include <stdio.h>

/*
Give permissions with the following command:
    $ sudo adduser $USER dialout
*/

using namespace std;

Serial::Serial(const std::string& dev_name, const uint32_t br): 
                m_br(br), m_dev_name(dev_name)
{
    connect_serial();

    tx_buff = new uint8_t[BUFF_SIZE];
    rx_buff = new uint8_t[BUFF_SIZE];
}

size_t Serial::ll_ser_read()
{
    memset(rx_buff, 0, BUFF_SIZE);

    size_t n = read(m_ser_handle, rx_buff, BUFF_SIZE);

    cout << "n = " << n << endl;

    for(int i=0; i<n; i++)	 /*printing only the received characters*/
        printf("%c",rx_buff[i]);

    return n;
}

void Serial::connect_serial()
{
    m_ser_handle = open(m_dev_name.c_str(), O_RDWR | O_NOCTTY); // todo: why the last two?

    if (m_ser_handle < 0)
        perror("Serial Port opening failed");

    set_tty_options(m_br);
}

Serial::~Serial()
{
    delete[] tx_buff;
    delete[] rx_buff;
}

void Serial::set_tty_options(uint32_t baudrate)
{
    uint32_t baud_bits;

    memset(&tty_opts, 0, sizeof(tty_opts));
    if (tcgetattr(m_ser_handle, &tty_opts) != 0)
        perror("Error while trying to get terminal attributes");

    // Control Modes settings
    tty_opts.c_cflag &= ~(PARENB|CSTOPB|CRTSCTS|CSIZE);
    tty_opts.c_cflag |= (CS8|CLOCAL|CREAD);

    // Local Modes settings
    tty_opts.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHONL|ISIG);

    // Input Modes settings
    tty_opts.c_iflag &= ~(IXON|IXOFF|IXANY);
    tty_opts.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);

    tty_opts.c_cc[VTIME] = 0;
    tty_opts.c_cc[VMIN] = 10; /* Read at least 10 characters */

    tty_opts.c_oflag &= ~OPOST;

    baud_bits = baud_map(baudrate);
    cfsetispeed(&tty_opts, baud_bits);
    cfsetospeed(&tty_opts, baud_bits);

    if (tcsetattr(m_ser_handle, TCSANOW, &tty_opts) != 0)
        perror("Error while trying to set terminal attributes");

    tcflush(m_ser_handle, TCIOFLUSH);
}

uint32_t Serial::baud_map(uint32_t br)
{
    uint32_t bits;
    switch(br)
    {
        case 115200: bits = B115200; break;
        default:
            std::cout << "Baudrate defaulting to 9600" << std::endl;
            bits = B9600;
    }

    return bits;
}

int main()
{
    Serial ser_handle("/dev/ttyACM0", 115200);

    ser_handle.ll_ser_read();





}

// Reference: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/