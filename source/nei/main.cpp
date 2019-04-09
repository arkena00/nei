#include <nei/entity.hpp>

#include <nei/utility.hpp>

int main()
{
    const nei::universe<1> universe{ 40 };
    nei::display(universe.units());

    nei::entity<1> neia{ universe };

    neia.live();


    for (auto concept : neia.concepts())
    {
        std::cout << "\nConcepts"
        << "\n_______"
        << "\n\tname : " << concept.name()
        << "\n\tpattern : " << concept.pattern
        << "\n\tbuffer : " << nei::to_string(concept.buffer);
    }

    return WORLD_DOMINATION_SUCCESS;
}