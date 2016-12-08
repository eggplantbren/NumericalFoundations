#ifndef NF_MonotonicFunction
#define NF_MonotonicFunction

#include <vector>
#include "DNest4/code/RNG.h"

namespace NF
{

class MonotonicFunction
{
    private:
        // Underlying coordinates
        std::vector<double> u;

        // The (increasing) function values
        std::vector<double> f;

        // Compute f from u
        void assemble();

    public:
        MonotonicFunction(size_t num_values);

        void from_prior(DNest4::RNG& rng);
        double perturb(DNest4::RNG& rng);
};


} // namespace NF

#endif

