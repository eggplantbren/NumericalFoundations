#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include "DNest4/code/RNG.h"

#include "BooleanLattice.h"
#include "MonotonicFunction.h"
#include "Valuations.h"

#include <set>

int main()
{
    DNest4::RNG rng(time(0));

    // Some valuations
    NF::Valuations v;
    v.generate(4, rng);

    // Print them
    std::cout<<v<<std::endl;

    return 0;
}

