#include <nei/entity.hpp>

#include <nei/utility.hpp>

int main()
{
    spdlog::set_pattern("%v");

    // test A X... A // A == A
    // test A B C D E // A < B < C ...
    auto data = "123479";
    //auto data = "111=3";

    const nei::universe<1> universe{ "ABAC00TZYZ0000000 salut test prout zeta " };
    nei::display(universe.units());

    nei::entity<1> neia{ universe };

    nei::analyser<1> an{ neia };
    an.process(universe.units());

    return WORLD_DOMINATION_SUCCESS;
}