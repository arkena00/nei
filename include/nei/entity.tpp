#include <nei/entity.hpp>
#include <nei/utility/bitset.hpp>
#include "concept.hpp"

namespace nei
{
    template<int Dimension>
    entity<Dimension>::entity(const nei::universe<Dimension>& universe)
         : universe_{ universe }
         , senses_{ *this }
         , analyser_{ *this }
    {}

    template<int Dimension>
    void entity<Dimension>::live()
    {
        analyser_.process(universe_.units());

        //senses_.process(0);
        //senses_.process(6);
        //senses_.process(17);
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
        analyser_.process(memory_);
        /*

            // check concept
            bool concept_known = false;

            for (const auto& concept : concepts_)
            {
                if (concept.pattern == r)
                {
                    concept.increase_comprehension();
                    concept_known = true;
                    break;
                }
            }
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
            //std::cout << "\n__" << result.ToString();

            ++linears[0];
        */
    }

    template<int Dimension>
    const nei::universe<Dimension>& entity<Dimension>::universe() const
    {
        return universe_;
    }
} // nei

