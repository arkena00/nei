#include <nei/entity.hpp>
#include <bitset>

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
        senses_.process();
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

    template<int Dimension>
    void entity<Dimension>::process_memory_analyse()
    {
        // input params
        unsigned int i = 0;
        unsigned int size = memory_.size();

        // output
        std::bitset<32> result;

        // initial atomic unit
        nei::unit_type u1 = memory_[i];
        nei::unit_type u2 = memory_[i];

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
         */
        for (i = 1; i != size; ++i)
        {
            // create variation variables x and y
            // apply functions from (inputs / concepts / atomic_ops) to x and y
            // u[x] & u[y]

            u2 = memory_[i];
            bool r0 = u1 == u2;
            //concepts_.add(r0);
            bool r1 = u1 ^ u2;
            std::cout << std::hex << "\n_i: " << i << " u1: " << u1 << " and " << u2  << " r0: " << r0 << "_" << r1;
            u1 = u2;
        }
    }

    template<int Dimension>
    const nei::universe<Dimension>& entity<Dimension>::universe() const
    {
        return universe_;
    }
} // nei

