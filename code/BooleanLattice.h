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
        // Element 0 = the falsity
        // Elements 1, 2, 4, 8, ... are the atoms
        std::vector<size_t> statements;

    public:
        // Constructor: specify number of atoms
        BooleanLattice(std::string name, size_t num_atoms);

        // Returns the size
        size_t size() const
        { return statements.size(); }

        // Join of two elements
        size_t join(size_t i, size_t j) const;

        // Meet of two elements
        size_t meet(size_t i, size_t j) const;

        // Does element i imply element j?
        bool implies(size_t i, size_t j) const;

        // Check whether statements (i, j, k) are disjoint
        bool disjoint(size_t i, size_t j, size_t k) const;

        // Printable representation (bits!) of a statement 
        std::string statement_to_string(size_t i) const;

        // Declare output operator as friend
        friend std::ostream& operator <<
                    (std::ostream& out, const BooleanLattice& bl);
};

std::ostream& operator << (std::ostream& out, const BooleanLattice& bl);

} // namespace NumericalFoundations2

#endif

