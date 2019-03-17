#include <nei/entity.hpp>

#include <nei/utility.hpp>

int main()
{
    const nei::universe<1> universe{ 40 };

    nei::entity<1> neia{ universe };

    nei::display(universe.units());

    neia.live();

    return WORLD_DOMINATION_SUCCESS;
}



