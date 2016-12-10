#ifndef NF_Valuations
#define NF_Valuations

#include <vector>
#include <ostream>
#include <tuple>

#include "BooleanLattice.h"
#include "DNest4/code/RNG.h"

/*
    Valuations to go along with statements in a lattice.
    They are represented as vectors of doubles --- there is no need for
    a class for this. But here are some functions for generating and
    testing valuations.
*/

namespace NF
{

// Generate some valuations to go along with a lattice.
// NB: Does not duplicate values!
std::vector<double> generate_valuations
        (const BooleanLattice& bl, DNest4::RNG& rng);

// Generate some valuations until we find some faithful ones.
std::vector<double> generate_good_valuations
    (const BooleanLattice& bl, DNest4::RNG& rng, bool fidelity_matters=true);

// Check fidelity of the valuations.
bool check_fidelity
        (const BooleanLattice& bl, const std::vector<double>& valuations);

// Check order of the valuations.
bool check_order
        (const BooleanLattice& bl, const std::vector<double>& valuations);

// Check "transformability to sum rule"
bool check_sum_rule
        (const BooleanLattice& bl, const std::vector<double>& valuations);

// Output a boolean lattice with valuations.
std::ostream& operator << 
        (std::ostream& out,
            const std::tuple<BooleanLattice, std::vector<double>>& blv);

} // namespace NF

#endif

