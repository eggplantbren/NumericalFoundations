#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include "DNest4/code/RNG.h"

#include "BooleanLattice.h"
#include "MonotonicFunction.h"
#include "Valuations.h"

int main()
{
    // A random number generator
    DNest4::RNG rng(time(0));

    // A boolean lattice
    NF::BooleanLattice bl("A", 3);

    // Some valuations
    std::vector<double> v = NF::generate_good_valuations(bl, rng);

    // Put into a tuple
    NF::BLV blv(bl, v);

    // Print it
    std::cout<<blv<<std::endl;

    // See if the sum rule applies.
    NF::check_sum_rule(blv, rng);

    return 0;
}

