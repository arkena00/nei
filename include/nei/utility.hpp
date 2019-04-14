#ifndef NEI_UTILITY_HPP
#define NEI_UTILITY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>

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

    template<class T>
    std::string to_string(const T& iterable)
    {
        std::stringstream ss;
        for (auto&& item : iterable)
        {
            ss << std::setfill('0') << std::setw(2) << std::hex << item << " ";
        }
        return ss.str();
    }
} // nei

#endif // NEI_UTILITY_HPP
