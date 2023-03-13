/** @file onion/ObjectiveFunction.hpp
 *  @brief This header introduces the ObjectiveFunction class interface.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef OBJECTIVEFUNCTION_HPP
#define OBJECTIVEFUNCTION_HPP

#include "NonCopyable.hpp"
#include "IdentifiedComponent.hpp"

namespace onion{

/** @class ObjectiveFunction
 *  @brief Defines the interface of ObjectiveFunction components.
 *  @param solution_t the type used to represent a solution to a problem.
 *  @param objective_value_t the type used to represent the value of a solution.
 *
 *  The ObjectiveFunction is responsible for assigning a value to a solution of a problem.
 *
 *  All algorithms are, in essence, ways of navigating the solution space. In this metaphore,
 *  the ObjectiveFunction can be interpreted as the compass that poits towards the right direction.
 *  Its the objective function that tells the algorithm if a solution A is better or worse than a solution B.
 *
 *  The ObjectiveFunction class is an [ADT](@ref ABSTRACTDATATYPE) used to represent this
 *  concept and define the protocol of this functionality.
 *
 *  This is one of the fundamental components of the Onion Framework, the others being
 *  the CreateOperator, the PerturbationOperator and the SelectOperator.
 *
 */
template< typename solution_t, typename objective_value_t>
class ObjectiveFunction : public NonCopyable, public IdentifiedComponent
{
public:

    /**
     * @brief Class constructor.
     */
    virtual ~ObjectiveFunction() = default;
    /**
     * @brief Assigns a value to a solution.
     * @param S A (possibly unitary) set of solutions to be evaluated.
     * @return A (possibly unitary) set of values that rank the solutions relatives to each other.
     */
    virtual objective_value_t operator()(const solution_t&) = 0;
};

}
#endif // OBJECTIVEFUNCTION_H
