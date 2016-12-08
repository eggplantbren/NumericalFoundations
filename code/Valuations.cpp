#include "Valuations.h"


#include <iostream>

namespace NF
{

std::vector<double> generate_valuations
                            (const BooleanLattice& bl, DNest4::RNG& rng)
{
    std::vector<double> v(bl.size());

    for(size_t i=0; i<v.size(); ++i)
        v[i] = 1000.0*rng.randn();

    return v;
}

std::vector<double> generate_good_valuations
            (const BooleanLattice& bl, DNest4::RNG& rng, bool fidelity_matters)
{
    std::vector<double> v;

    // Generate valuations until they satisfy order (and optionally, fidelity)
    while(true)
    {
        v = generate_valuations(bl, rng);
        if(check_order(bl, v))
        {
            if((!fidelity_matters) || check_fidelity(bl, v))
                break;
        }
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

bool check_order
        (const BooleanLattice& bl, const std::vector<double>& valuations)
{
    // Alias
    const auto& v = valuations;

    // Loop over all triples, but only bother with disjoint triples
    for(size_t i=0; i<bl.size(); ++i)
        for(size_t j=0; j<bl.size(); ++j)
            for(size_t k=0; k<bl.size(); ++k)
                if(bl.disjoint(i, j, k))
                    if(v[i] > v[j])
                        if(v[bl.join(i, k)] <= v[bl.join(j, k)])
                            return false;
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

} // namespace NF

