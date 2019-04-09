#include <nei/entity.hpp>
#include <bitset>
#include "concept.hpp"

namespace nei
{
    template<int Dimension>
    entity<Dimension>::entity(const nei::universe<Dimension>& universe)
         : universe_{ universe }
         , senses_{ *this }
    {}

    template<int Dimension>
    void entity<Dimension>::live()
    {
        senses_.process(0);
        senses_.process(6);
    }

    template<int Dimension>
    void entity<Dimension>::notify_sense_update()
    {
        std::cout << "\nnotify_sense_update\n";
        // sense buffer updated, copy it to active memory
        memory_.resize(senses_.buffer().size());
        std::copy(senses_.buffer().begin(), senses_.buffer().end(), memory_.begin());

        // analyse
        process_memory_analyse();
    }

    //! generate atomic couples ( couple of 2 ) (n , n)
    //! process couples orders
    // [A B A] C [D (E D] E) F G // 3 N X N concept
    // A B, B C, C D
    // (r0), (r1), (r2)
    /*! nlvl| indexes : result
     * n0| 0 1 : 0 -> concept c0
     * n1| 1 2 : 0 -> concept c1
     * n2| 2 3 : 0 -> concept c1
     *
     * 0 1 : 0
     * 0 2 : 1
     * 0 3 : 0
     * 1 2 : 0
     * 1 3 : 0
     * 2 3 : 0
     *
     * r0 = 0 1 0 0 0 0 store to concept c0
     * r0 & concept[n]
     * r0 & shift_concept
     *
     * create variation variables x and y
     * apply functions from (inputs / concepts / atomic_ops) to x and y
     */
    template<int Dimension>
    void entity<Dimension>::process_memory_analyse()
    {
        // linear input params
        unsigned int input_index = 0;
        unsigned int input_size = memory_.size();

        // output
        std::bitset<4> result;

        // input loop // processing loop
        while (input_index < input_size)
        {
            //std::cout << "\n__" << input_index;

            // range
            unsigned int range_begin = input_index;
            unsigned int range_end = input_size;
            unsigned int range_index = range_begin + 1; // x : input, y : range

            int end = 0;
            bool concept_found = false;

            // range loop
            for (; range_index != range_end; ++range_index)
            {
                //std::cout << "\n__" << range_index;
                // variations
                auto x = input_index;
                auto y = range_index;

                // data
                auto datax = memory_[x];
                auto datay = memory_[y];

                // function
                auto r = datax == datay; // CMP(datax, datay)
                // store result
                result.set(range_index, r);

                //if (r) std::cout << "_______" << x;
                if (r)
                {
                    concept_found = true;
                    end = range_index; // last true operation
                }

                std::cout << std::hex << "\n_i: " << input_index << " u1: " << datax << " and " << datay  << " r: " << r;
            }

            // check concept
            bool concept_known = false;
            /*
            for (const auto& concept : concepts_)
            {
                if (concept.pattern == r)
                {
                    concept.increase_comprehension();
                    concept_known = true;
                    break;
                }
            }*/
            if (!concept_known && concept_found)
            {
                nei::concept concept;
                concept.pattern = result;
                concept.buffer.resize(end+1);
                std::copy(memory_.begin(), memory_.begin() + end + 1, concept.buffer.begin());
                //concept.algo = (x, y, r, OP)
                concepts_.emplace_back(std::move(concept));
            }

            // result
            std::cout << "\n__" << result;

            ++input_index;
        }
    }

    template<int Dimension>
    const nei::universe<Dimension>& entity<Dimension>::universe() const
    {
        return universe_;
    }
} // nei

