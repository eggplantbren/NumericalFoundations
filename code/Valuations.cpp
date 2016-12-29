#include "Valuations.h"

namespace NF
{

Valuations::Valuations()
{

}

void Valuations::generate(size_t size, DNest4::RNG& rng)
{
    // Generate a vector
    std::vector<double> x(size);
    for(size_t i=0; i<size; ++i)
        x[i] = 1000.0*rng.randn();

    // Duplicates?
    if(rng.rand() <= 0.5)
    {
        double prob = pow(10.0, -6*rng.rand());
        for(size_t i=0; i<size; ++i)
            if(rng.rand() <= prob)
                x[i] = x[rng.rand_int(size)];
    }

    // Insert into the multiset
    v.clear();
    for(size_t i=0; i<x.size(); ++i)
        v.insert(x[i]);
}

std::vector<double> Valuations::as_vector() const
{
    std::vector<double> result(v.size());

    int i = 0;
    for(auto it=v.begin(); it != v.end(); ++it)
    {
        result[i] = *it;
        ++i;
    }

    return result;
}

std::ostream& operator << (std::ostream& out, const Valuations& v)
{
    for(auto it=v.v.begin(); it != v.v.end(); ++it)
        out<<(*it)<<' ';

    return out;
}

} // namespace NF

