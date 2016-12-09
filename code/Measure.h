#ifndef NF_Measure
#define NF_Measure

#include <vector>
#include <stdlib.h>
#include "DNest4/code/RNG.h"

namespace NF
{

/*
* An object of this class represents a measure
*/

class Measure
{
    private:
        std::vector<double> atom_values;

    public:
        Measure(size_t num_atoms);

        void from_prior(DNest4::RNG& rng);
        double perturb(DNest4::RNG& rng);
};

} // namespace NF

#endif

