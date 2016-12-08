#include "BooleanLattice.h"

#include <cmath>

namespace NumericalFoundations2
{

BooleanLattice::BooleanLattice(std::string name, size_t num_atoms)
:name(name)
,num_atoms(num_atoms)
,statements(pow(2, num_atoms))
{
    // Create the statements
    for(size_t i=0; i<statements.size(); ++i)
        statements[i] = i;
}

std::ostream& operator << (std::ostream& out, const BooleanLattice& bl)
{
    out<<bl.name;
    return out;
}

} // namespace NumericalFoundations2

