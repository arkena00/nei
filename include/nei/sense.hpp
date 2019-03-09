#ifndef NEI_SENSE_HPP
#define NEI_SENSE_HPP

#include <nei/buffer.hpp>

namespace nei
{
    //! senses read data from environment and store it in a sense buffer
    class sense
    {
        sense() = default;

        nei::buffer buffer;
    };

    class view_sense : sense
    {
        //lookat(x, range)
    };

} // nei

#endif // NEI_SENSE_HPP
