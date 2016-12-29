#ifndef NF_Valuations
#define NF_Valuations

#include <set>
#include <stdlib.h>
#include <vector>
#include <ostream>

#include "RNG.h"

/*
* A class for sets of values.
*/

namespace NF
{

class Valuations
{
    private:
        // The actual values, sorted.
        std::multiset<double> v;

    public:
        // A do-nothing constructor.
        Valuations();

        // Generate some values
        void generate(size_t size, RNG& rng);

        // Convert to a vector and return.
        std::vector<double> as_vector() const;

        // Make output a friend
        friend std::ostream& operator <<
                            (std::ostream& out, const Valuations& v);
};

// Output to stream
std::ostream& operator << (std::ostream& out, const Valuations& v);

} // namespace NF

#endif

