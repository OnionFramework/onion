#ifndef NEIGHBORHOODOPERATOR_HPP
#define NEIGHBORHOODOPERATOR_HPP

#include "NonCopyable.hpp"
#include "ComponentID.hpp"

namespace onion{

template< typename solution_t, typename transition_t>
class NeighborhoodOperator : public NonCopyable, public ComponentID
{
public:

    virtual ~NeighborhoodOperator() = default;
    virtual transition_t operator()(const solution_t &) = 0;
};

}

#endif // NEIGHBORHOODOPERATOR_H
