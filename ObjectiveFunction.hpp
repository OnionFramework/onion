/** @file onion/ObjectiveFunction.hpp
 *  @brief This header introduces the ObjectiveFunction class interface.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef OBJECTIVEFUNCTION_HPP
#define OBJECTIVEFUNCTION_HPP

#include "NonCopyable.hpp"
#include "ComponentID.hpp"

namespace onion{

/** @class ObjectiveFunction
 *  @brief Abstract Data Type that defines the ObjectiveFuntion component.
 *  @param solution_t the type used to represent a solution to a problem.
 *  @param objective_value_t the type used to represent the value of a solution.
 *
 *  In simple terms, ObjectiveFunction determines the value of a particular solution to a problem,
 *  based on the compact data used to represent a problem instance.
 *
 *  All algorithms are, in essence, ways of navigating the solution space. In this metaphore,
 *  the ObjectiveFunction is the compass that poits towards the right direction.
 *  It is the objective function that tells the algorithm if a solution **A**
 *  is better or worse than some other alternative **B**.
 *
 *  @note
 *  ObjectiveFunction is an <a href="./md__glossary.html#abstract_data_type">Abstract Data Type</a>.
 *  It means it provides no functionality and can't be instantiated.
 *  Instead, its purpose is to define unambiguously what "Objective" means in the framewok's context.
 *  Actual functionality will be defined later by concrete implementions in derived classes.
 *
 */
template< typename solution_t, typename objective_value_t>
class ObjectiveFunction : public NonCopyable, public ComponentID
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
