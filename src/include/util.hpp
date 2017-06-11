#ifndef UTIL_HPP
#define UTIL_HPP
#include <cstdint>

template <typename T>
struct Page{
    T key;
    T value;
    size_t _frequency;
};


#endif // UTIL_HPP
