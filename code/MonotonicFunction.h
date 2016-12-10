#ifndef NF_MonotonicFunction
#define NF_MonotonicFunction

#include <vector>
#include <ostream>

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

        // Check whether the f values are too close together
        bool is_degenerate() const;

    public:
        MonotonicFunction(size_t num_values);

        void from_prior(DNest4::RNG& rng);
        double perturb(DNest4::RNG& rng);

        // Output
        friend std::ostream& operator << (std::ostream& out,
                                    const MonotonicFunction& mf);
};

// Output
std::ostream& operator << (std::ostream& out, const MonotonicFunction& mf);

} // namespace NF

#endif

