#ifndef OBJECTIVEFUNCTION_HPP
#define OBJECTIVEFUNCTION_HPP

#include "NonCopyable.hpp"
#include "ComponentID.hpp"

namespace onion{

template< typename transition_t, typename objective_measure_t = unsigned >
class ObjectiveFunction : public NonCopyable, public ComponentID
{
public:

    virtual ~ObjectiveFunction() = default;
    virtual objective_measure_t operator()(const transition_t&) = 0;
};

}\
#endif // OBJECTIVEFUNCTION_H
