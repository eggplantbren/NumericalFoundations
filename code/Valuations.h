#ifndef NF_Valuations
#define NF_Valuations

#include <vector>
#include <ostream>
#include <tuple>

#include "BooleanLattice.h"
#include "DNest4/code/RNG.h"

/*
    Valuations to go along with statements in a lattice.
    They are represented as vectors of doubles --- a class is overkill for
    this. But here are some functions for generating and
    testing valuations.
*/

namespace NF
{

// A type for Boolean lattices with valuations.
typedef std::tuple<BooleanLattice, std::vector<double>> BLV;

// Generate some valuations to go along with a lattice.
// NB: Does not duplicate values!
std::vector<double> generate_valuations
        (const BooleanLattice& bl, DNest4::RNG& rng);

// Generate some valuations until we find some that satisfy order and
// (optionally) fidelity.
std::vector<double> generate_good_valuations
    (const BooleanLattice& bl, DNest4::RNG& rng, bool fidelity_matters=true);

// Check fidelity of the valuations.
bool check_fidelity(const BLV& lattice);

// Check order of the valuations.
bool check_order(const BLV& lattice);

// Check "transformability to sum rule"
bool check_sum_rule(const BLV& blv, DNest4::RNG& rng);

// Output a boolean lattice with valuations.
std::ostream& operator << (std::ostream& out, const BLV& blv);

} // namespace NF

#endif

