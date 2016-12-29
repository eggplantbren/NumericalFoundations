#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include "RNG.h"

#include "BooleanLattice.h"
#include "Valuations.h"

#include <set>

int main()
{
    NF::RNG rng(time(0));

    // Some valuations
    NF::Valuations v;
    v.generate(4, rng);

    // Print them
    std::cout<<v<<std::endl;

    return 0;
}

