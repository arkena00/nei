#ifndef NEI_SENSE_HPP
#define NEI_SENSE_HPP

#include <nei/buffer.hpp>
#include <nei/type.hpp>

namespace nei
{
    template<int D> class entity;
    template<int D> class universe;

    //! senses read data from universe and store it in a sense buffer
    template<int Dimension>
    class sense
    {
    public:
        sense(nei::entity<Dimension>& entity);

        void process(int n);

        auto& buffer();

    private:
        nei::entity<Dimension>& entity_;
        //nei::buffer<Dimension> buffer_;
        std::array<nei::unit_type, 4> buffer_;
    };
} // nei

#include "sense.tpp"

#endif // NEI_SENSE_HPP
