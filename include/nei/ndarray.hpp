#ifndef NEI_NDARRAY_HPP
#define NEI_NDARRAY_HPP

#include <array>

namespace nei
{
    template<unsigned int N>
    using ndarray = std::array<char, N>;
} // nei

#endif // NEI_NDARRAY_HPP
