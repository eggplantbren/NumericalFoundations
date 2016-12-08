#ifndef NumericalFoundations2_BooleanLattice
#define NumericalFoundations2_BooleanLattice

#include <stdlib.h>
#include <vector>
#include <string>
#include <ostream>

namespace NumericalFoundations2
{

/*
* An object of this class represents a boolean lattice of statements
*/

class BooleanLattice
{
    private:
        // Name
        std::string name;

        // Number of atoms
        size_t num_atoms;

        // Vector of statements
        // Represent statements using the bits of an unsigned int
        std::vector<size_t> statements;

    public:
        // Constructor: specify number of atoms
        BooleanLattice(std::string name, size_t num_atoms);

        // Join of two elements

        // Declare output operator as friend
        friend std::ostream& operator <<
                    (std::ostream& out, const BooleanLattice& bl);
};

std::ostream& operator << (std::ostream& out, const BooleanLattice& bl);

} // namespace NumericalFoundations2

#endif

