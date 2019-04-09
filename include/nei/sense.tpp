#include <nei/entity.hpp>

#include <nei/universe.hpp>
#include <nei/utility.hpp>

namespace nei
{
    template<int Dimension>
    sense<Dimension>::sense(nei::entity<Dimension>& entity) : entity_{ entity }
    {

    }

    // we transfer universe data to sense buffer using entity position
    template<int Dimension>
    void sense<Dimension>::process(int n)
    {
        std::cout << "\nprocess buffer\n";
        for(unsigned int i = 0; i != buffer_.size(); ++i)
        {
            buffer_[i] = entity_.universe().unit_at(n + i);
        }
        nei::display(buffer_);

        // tell the entity to process the buffer
        entity_.notify_sense_update();
    }

    template<int Dimension>
    auto& sense<Dimension>::buffer()
    {
        return buffer_;
    }
} // nei