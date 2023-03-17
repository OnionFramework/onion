/** @file onion/SelectOperator.hpp
 *  @brief This header introduces the SelectOperator class interface.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef SELECTOPERATOR_HPP
#define SELECTOPERATOR_HPP

#include "ComponentID.hpp"
#include "NonCopyable.hpp"
#include "ComparissonOperator.hpp"

namespace onion{

/** @class SelectOperator
 *  @brief Defines the interface of SelectOperator components.
 *  @param objective_value_t.
 *  @param objective_value_t the type used to represent the value of a solution.
 *
 *  The ObjectiveFunction is responsible for assigning a value to a solution of a problem.
 *
 *  All algorithms are, in essence, ways of navigating the solution space. In this metaphore,
 *  the ObjectiveFunction can be interpreted as the compass that poits towards the right direction.
 *  It is the objective function that tells the algorithm if a solution A is better or worse than a solution B.
 *
 *  The ObjectiveFunction class is an ADT used to represent this
 *  concept and define the protocol of this functionality.
 *
 *  This is one of the fundamental components of the Onion Framework, the others being
 *  the CreateOperator, the PerturbationOperator and the SelectOperator.
 *
 */
template< typename objective_value_t,
          typename objective_function_result_t,
          ComparissonOperator<objective_value_t> compare >
class SelectOperator : public NonCopyable, public ComponentID
{
public:
    virtual ~SelectOperator() = default;
    virtual  void operator()(const objective_value_t& best_sofar,
                             const objective_function_result_t& candidates) = 0;

};

}


#endif // SELECTOPERATOR_H
