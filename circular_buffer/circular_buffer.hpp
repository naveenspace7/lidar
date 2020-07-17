#include <exception>

class BufferSizeExceeded: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Buffer Size Exceeded";
    }
} BufferSizeExceeded;

class BufferSizeNull: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Buffer Empty";
    }
} BufferSizeNull;

template <typename T, int N>
class CirBuff
{
public:
    CirBuff();

    ~CirBuff();

    void push_back(const T& new_data);
    T pop_front();

    bool empty();

private:
    T * data;
    T * start_index, * end_index;
    T * start_boundary, * end_boundary;

    size_t size;
};