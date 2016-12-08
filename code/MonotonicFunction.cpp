#include "MonotonicFunction.h"

#include "DNest4/code/Distributions/Laplace.h"

namespace NF
{

MonotonicFunction::MonotonicFunction(size_t num_values)
:u(num_values)
,f(num_values)
{

}

void MonotonicFunction::from_prior(DNest4::RNG& rng)
{
    for(double& uu: u)
        uu = rng.rand();

    assemble();
}

void MonotonicFunction::assemble()
{
    DNest4::Laplace laplace;

    f[0] = 1000*laplace.cdf_inverse(u[0]);
    for(size_t i=1; i<f.size(); ++i)
        f[i] = f[i-1] - 1000*log(1.0 - u[i]);
}

} // namespace NF

