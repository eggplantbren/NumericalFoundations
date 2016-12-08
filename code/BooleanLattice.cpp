#include "BooleanLattice.h"

#include <cmath>
#include <stdexcept>
#include <sstream>

namespace NF
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

size_t BooleanLattice::join(size_t i, size_t j) const
{
    if(i >= statements.size() || j >= statements.size())
        throw std::domain_error("Out of bounds.");
    return i | j;
}

size_t BooleanLattice::meet(size_t i, size_t j) const
{
    if(i >= statements.size() || j >= statements.size())
        throw std::domain_error("Out of bounds.");
    return i & j;
}

bool BooleanLattice::implies(size_t i, size_t j) const
{
    if(i >= statements.size() || j >= statements.size())
        throw std::domain_error("Out of bounds.");

    // i => j is equivalent in meaning to (i, not j) being false
    return (i & (~j)) == 0;
}

bool BooleanLattice::disjoint(size_t i, size_t j, size_t k) const
{
    if(i >= statements.size()
        || j >= statements.size()
        || k >= statements.size())
            throw std::domain_error("Out of bounds.");
    return (meet(i, j) == 0) && (meet(i, k) == 0) && (meet(j, k) == 0);
}

std::string BooleanLattice::statement_to_string(size_t i) const
{
    if(i >= statements.size())
        throw std::domain_error("Out of bounds.");

    // Start with the lattice name
    std::stringstream ss;

    // See if each atom implies statement i
    // The atoms are elements 1, 2, 4, 8, ...
    for(size_t a=1; a<=num_atoms; ++a)
        ss<<((implies(pow(2, a-1), i))?('1'):('0'));

    return ss.str();
}

std::ostream& operator << (std::ostream& out, const BooleanLattice& bl)
{
    out<<bl.name<<' ';
    for(size_t i=0; i<bl.statements.size(); ++i)
        out<<bl.statement_to_string(i)<<' ';
    return out;
}

} // namespace NF

