#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include "DNest4/code/RNG.h"

#include "BooleanLattice.h"
#include "Valuations.h"

int main()
{
    // A random number generator
    DNest4::RNG rng(time(0));

    // A boolean lattice
    NumericalFoundations2::BooleanLattice bl("A", 2);

    // Some valuations
    std::vector<double> v =
        NumericalFoundations2::generate_good_valuations(bl, rng);

    // Put into a tuple
    std::tuple<NumericalFoundations2::BooleanLattice, std::vector<double>>
                blv(bl, v);

    std::cout<<"A boolean lattice and some good valuations:"<<std::endl;
    std::cout<<blv<<std::endl;
    NumericalFoundations2::check_order(bl, v);

    return 0;
}

