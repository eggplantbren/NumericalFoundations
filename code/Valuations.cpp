#include "Valuations.h"

namespace NumericalFoundations2
{

std::vector<double> generate_valuations
                            (const BooleanLattice& bl, DNest4::RNG& rng)
{
    std::vector<double> v(bl.size());

    for(size_t i=0; i<v.size(); ++i)
        v[i] = 1000.0*rng.randn();

    return v;
}

std::vector<double> generate_faithful_valuations
                            (const BooleanLattice& bl, DNest4::RNG& rng)
{
    std::vector<double> v;

    // Generate valuations until they're faithful
    while(true)
    {
        v = generate_valuations(bl, rng);
        if(check_fidelity(bl, v))
            break;
    }

    return v;
}

bool check_fidelity
        (const BooleanLattice& bl, const std::vector<double>& valuations)
{
    // Loop over all pairs of statements
    for(size_t i=0; i<bl.size(); ++i)
    {
        for(size_t j=0; j<bl.size(); ++j)
        {
            // Valuations must encode implication.
            if(bl.implies(i, j) && valuations[j] < valuations[i])
                return false;
        }
    }
    return true;
}

// Output a boolean lattice with valuations.
std::ostream& operator << 
        (std::ostream& out,
            const std::tuple<BooleanLattice, std::vector<double>>& blv)
{
    // Unpack tuple
    auto& bl = std::get<0>(blv);
    auto& valuations = std::get<1>(blv);

    // Output the lattice
    out<<bl;

    // Output the values
    for(double v: valuations)
        out<<v<<' ';

    return out;
}

} // namespace NumericalFoundations2

