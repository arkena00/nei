#include <nei/analyser.hpp>

#include <nei/utility/bitset.hpp>
#include <nei/log.hpp>

#include <array>
#include <cstddef>
#include "concept.hpp"

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

    /*
    inputs

    process_loop
        range_loop
            variables
            datas = data[variables]
            r = operation(datas)
            if (r) store_result
        range_loop_end
    process_loop_end*/


    template<int Dimension>
    void analyser<Dimension>::process(std::vector<nei::unit_type> data)
    {
        data_ = data;

        std::cout << "\nanalyser\n";
        nei::display(data_);
        std::cout << "\n";

        // linear input params
        linears_.clear();
        linear_add(0);
        linear_add((int)data_.size());

        // output
        nei::bitset<> result(data_.size(), false);

        // array
        variables_.resize(2); // 2 variables
        datas_.resize(2); // 2 datas

        // input loop // processing loop
        while (linears_[0] < linears_[1])
        {
            //
            std::size_t result_begin = 0;
            std::size_t result_end = 0;
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
                    result_begin = range_begin;
                    result_end = range_index + 1;

                    nei::concept concept;



                    spdlog::info("linear_index: {:d}, range_index: {:d} OP_EQUAL {:x} {:x} {:} {:}", linears_[0], range_index, datas_[0], datas_[1], result, nei::to_string(data_, result_begin, result_end));
                    result.reset();
                }

                //spdlog::info("linear_index: {:d}, range_index: {:d} OP_EQUAL {:x} {:x}", linears_[0], range_index, datas_[0], datas_[1]);
            }
            //////////////////////////////////////////// close range


            // result
            //std::cout << "\n__" << result.ToString();

            ++linears_[0];
        }

        // concept coherence analyser
        /*
        for (auto c : concepts_)
        {

        }*/
    }
} // nei