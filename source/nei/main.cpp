#include <nei/entity.hpp>

int main()
{
    const nei::universe<1> universe{ 40 };

    nei::entity<1> neia{ universe };

    universe.display();

    neia.live();

    return WORLD_DOMINATION_SUCCESS;
}



