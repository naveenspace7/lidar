#include <iostream>
#include <cstdint>
#include <algorithm>

#include "circular_buffer.hpp"

// using namespace std;

template<typename T, int N>
bool CirBuff<T,N>::empty()
{
    return size == 0;
}

template<typename T, int N>
CirBuff<T,N>::CirBuff(): data(new T[N])
{
    start_index = data;
    end_index   = data;

    start_boundary = data;
    end_boundary = &data[N-1];
}

template<typename T, int N>
CirBuff<T,N>::~CirBuff()
{
    delete[] data;
}

template<typename T, int N>
void CirBuff<T,N>::push_back(const T& new_data)
{
    if (size == N) throw BufferSizeExceeded;

    *end_index = new_data;

    if (end_index + 1 > end_boundary)
        end_index = start_boundary;
    else end_index++;

    size++;
}

template<typename T, int N>
T CirBuff<T,N>::pop_front()
{
    if (size == 0)
        throw BufferSizeNull;

    T return_data = *start_index;

    if (start_index + 1 > end_boundary)
        start_index = start_boundary;
    else
        start_index++;

    --size;

    return return_data;
}

int main()
{
    CirBuff<int, 5> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(7);

    // cout << "next" << endl;
    // cout << v.pop_front() << endl;
    // cout << v.pop_front() << endl;
    // cout << v.pop_front() << endl;
    // cout << v.pop_front() << endl;
    // // cout << v.pop_front() << endl;
    // v.push_back(10);
    // cout << "next" << endl;
    // cout << v.pop_front() << endl;
    // cout << v.pop_front() << endl;

    // cout << v.pop_front() << endl;
    // v.push_back(5);

    // for( int it : v )
    //     std::cout << it << std::endl;
}