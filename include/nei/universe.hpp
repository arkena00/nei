#ifndef NEI_ENVIRONMENT_HPP
#define NEI_ENVIRONMENT_HPP

//! an environment is a n-dimension world observable by neia
//! neia doesn't need to "live" in the environment

#include <nei/type.hpp>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cassert>

namespace nei
{
    template<int Dimension>
    class universe
    {
    public:
        universe(unsigned int size)
        {
            for(unsigned int i = 0; i != size; ++i)
            {
                auto unit_value = unit_type{ 1 };
                units_.emplace_back(std::move(unit_value));
            }
            std::iota(units_.begin(), units_.end(), 0);
            units_[0] = 'A';
            units_[1] = 'B';
            units_[2] = 'A';
            units_[3] = '0';

            units_[7] = 'A';
            units_[8] = 'B';
            units_[9] = 'A';
            units_[10] = 'Z';
        }

        auto unit_at(unsigned int n) const
        {
            assert(n < units_.size() && n >= 0);
            return units_[n];
        }

        const auto& units() const
        {
            return units_;
        }

    private:
        std::vector<nei::unit_type> units_;
    };
} // nei

#endif // NEI_ENVIRONMENT_HPP
