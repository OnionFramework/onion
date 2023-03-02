#ifndef OBJECTIVEFUNCTION_HPP
#define OBJECTIVEFUNCTION_HPP

#include "NonCopyable.hpp"
#include "IdentifiedComponent.hpp"

namespace onion{

template< typename transition_t, typename objective_measure_t>
class ObjectiveFunction : public NonCopyable, public IdentifiedComponent
{
public:

    virtual ~ObjectiveFunction() = default;
    virtual objective_measure_t operator()(const transition_t&) = 0;
};

}
#endif // OBJECTIVEFUNCTION_H
