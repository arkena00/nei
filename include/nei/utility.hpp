#ifndef NEI_UTILITY_HPP
#define NEI_UTILITY_HPP

#include <iomanip>
#include <iostream>

namespace nei
{
    template<class T>
    void display(const T& iterable)
    {
        for (auto&& item : iterable)
        {
            std::cout << std::setfill('0') << std::setw(2) << std::hex << item << " ";
        }
    }
} // nei

#endif // NEI_UTILITY_HPP
