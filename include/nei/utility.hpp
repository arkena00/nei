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
            std::cout << (char)item << " ";
        }
    }

    template<class T>
    void display(const T& iterable, std::size_t index_begin, std::size_t index_end)
    {
        for (auto i = index_begin; i != index_end; ++i)
        {
            std::cout << (char)iterable[i] << " ";
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

    template<class T>
    std::string to_string(const T& iterable, std::size_t index_begin, std::size_t index_end)
    {
        std::stringstream ss;
        for (auto i = index_begin; i != index_end; ++i)
        {
            ss << iterable[i] << " ";
        }
        return ss.str();
    }
} // nei

#endif // NEI_UTILITY_HPP
