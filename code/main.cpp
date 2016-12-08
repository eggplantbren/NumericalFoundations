#include <iostream>
#include "BooleanLattice.h"

int main()
{
    std::cout<<"Welcome to NumericalFoundations 2"<<std::endl;
    std::cout<<"Here is a Boolean lattice: \n"<<std::endl;

    NumericalFoundations2::BooleanLattice bl("a", 3);
    std::cout<<bl<<std::endl;

    return 0;
}

