#ifndef NumericalFoundations2_Valuations
#define NumericalFoundations2_Valuations

#include <vector>
#include <ostream>
#include <tuple>

#include "BooleanLattice.h"
#include "DNest4/code/RNG.h"

namespace NumericalFoundations2
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

// Output a boolean lattice with valuations.
std::ostream& operator << 
        (std::ostream& out,
            const std::tuple<BooleanLattice, std::vector<double>>& blv);

} // namespace NumericalFoundations2

#endif

