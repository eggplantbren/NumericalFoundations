#include "MonotonicFunction.h"

#include "DNest4/code/Distributions/Laplace.h"
#include "DNest4/code/Utils.h"

namespace NF
{

MonotonicFunction::MonotonicFunction(size_t num_values)
:u(num_values)
,f(num_values)
{

}

void MonotonicFunction::from_prior(DNest4::RNG& rng)
{
    do
    {
        for(double& uu: u)
            uu = rng.rand();

        assemble();
    }while(is_degenerate());
}

bool MonotonicFunction::is_degenerate() const
{
    return (f[f.size()-1] - f[0]) <= 0.01;
}

double MonotonicFunction::perturb(DNest4::RNG& rng)
{
    int reps = 1;
    if(rng.rand() <= 0.5)
        reps += static_cast<int>(pow(10.0, 2*rng.rand()));

    int which;
    for(int i=0; i<reps; ++i)
    {
        which = rng.rand_int(u.size());
        u[which] += rng.randh();
        DNest4::wrap(u[which], 0.0, 1.0);
    }

    assemble();

    if(is_degenerate())
        return -1E300;

    return 0.0;
}

std::vector<double> MonotonicFunction::apply(const std::vector<double>& v) const
{
    // Calculate the rank of each element of v
    std::vector<int> ranks(v.size());
    for(size_t i=0; i<v.size(); ++i)
    {
        ranks[i] = 0;   // Count how many elements are beaten by element i
        for(size_t j=0; j<v.size(); ++j)
        {
            if(v[i] > v[j])
                ++ranks[i];
        }
    }

    // Construct result vector
    std::vector<double> result(v.size());
    for(size_t i=0; i<v.size(); ++i)
        result[i] = f[ranks[i]];

    return result;
}

void MonotonicFunction::assemble()
{
    DNest4::Laplace laplace;

    f[0] = 1000*laplace.cdf_inverse(u[0]);
    for(size_t i=1; i<f.size(); ++i)
        f[i] = f[i-1] - 1000*log(1.0 - u[i]);
}

std::ostream& operator << (std::ostream& out, const MonotonicFunction& mf)
{
    for(double ff: mf.f)
        out<<ff<<' ';
    return out;
}

} // namespace NF

