#include <nei/analyser.hpp>

#include <nei/utility/bitset.hpp>
#include <spdlog/spdlog.h>

#include <array>
#include <cstddef>

namespace nei
{
    template<int Dimension>
    analyser<Dimension>::analyser(nei::entity<Dimension>& entity) : entity_{ entity }
    {}

    template<int Dimension>
    void analyser<Dimension>::linear_add(int value)
    {
        linears_.push_back(value);
    }
    template<int Dimension>
    void analyser<Dimension>::variable_add(int value)
    {
        variables_.push_back(value);
    }

    template<int Dimension>
    void analyser<Dimension>::process(std::vector<nei::unit_type> data)
    {
        data_ = data;

        // linear input params
        linear_add(0);
        linear_add(data_.size());
        // output
        nei::bitset<> result(4, false);

        // array
        variables_.resize(2); // 2 variables
        datas_.resize(2); // 2 datas

        // input loop // processing loop
        while (linears_[0] < linears_[1])
        {
            //
            std::size_t end = 0;
            bool concept_found = false;

            //////////////////////////////////////////// make range
            // range
            auto range_begin = linears_[0];
            auto range_end = linears_[1];
            auto range_index = range_begin + 1; // x : input, y : range

            // linear context
            variables_[0] = linears_[0];

            // range loop
            for (; range_index != range_end; ++range_index)
            {
                // range context
                variables_[1] = range_index; //linears[1];

                // data
                datas_[0] = data_[variables_[0]];
                datas_[1] = data_[variables_[1]];

                // function
                // auto r[0] = atomic_op(op[0], var[0], var[1])

                auto r = datas_[0] == datas_[1]; // operations[n](datas...)
                // store result
                result.set(range_index, r);

                if (r)
                {
                    concept_found = true;
                    end = range_index; // last true operation
                }

                spdlog::info("linear_index: {:d}, range_index: {:d} OP_EQUAL {:x} {:x}", linears_[0], range_index, datas_[0], datas_[1]);
            }
            //////////////////////////////////////////// close range


            // result
            //std::cout << "\n__" << result.ToString();

            ++linears_[0];
        }
    }
} // nei