/** @file onion/PerturbationParameterOperator.hpp
 *  @brief This header defines the PerturbationParameterOperator ADT.
 *
 *  <h3><a id="PerturbationParameterOperator_BK">Background</a></h3>
 *
 *  A regular Perturbation operator receives a solution to a problem and produces
 *  a (possibly unitary) set of new **complete** candidate solutions.
 *  It does that through the repeated application of a transformation function
 *  **T** on solution **S** as detailed <a href="_perturbation_operator_8hpp.html">here</a>.
 *
 *  To create complete solutions is not advisable nor possible in many cases.
 *  It results in applications that are unecessarily slow or demand unafordable ammounts of memory.
 *
 *  Usually, the solution in these cases involves performing perturbation,
 *  evaluation and, sometimes, selection in a single pass.
 *
 *  The perturbation step in these procedures ***does not*** creates complete solutions.
 *  Instead, it generates a series of *transformation* operations (small modifications to the original solution).
 *  The value of the *potential solutions* that would be created by these transformations
 *  is evaluated considering the difference in the original value caused by the transformation. In other words:
 *
 *  <b>v<sub>i</sub> = v<sub>0</sub> + D( S,T(P<sub>i</sub>) )</b>
 *
 *  where,
 *
 *  <b>v<sub>i</sub></b>   : value of the ith candidate solution.<br>
 *  <b>v<sub>0</sub></b>   : value of the current solution.<br>
 *  <b>S</b>   : current solution.<br>
 *  <b>T(P<sub>i</sub>)</b>   : transformation.<br>
 *  <b>P<sub>i</sub></b>    : ith parameter passed to the transformation function.
 *  <b>D(S,T<sub>i</sub>)</b>   : Delta objective function.<br>
 *
 *  Most of the concepts above were already described
 *  <a href="_perturbation_operator_8hpp.html">here</a>, but there are some important differences.
 *
 *  1. **T** here creates transformations, not complete solutions. Therefore, it depends only on <b>P<sub>i</sub></b>.
 *  2. The **D(S,T)** function receives a solution and a transformation as parameters and
 *  returns the ***difference in the value of the solution*** caused by the transformation <b>T(P<sub>i</sub>)</b>.
 *  Because of that we name it **DeltaObjective** function.
 *
 *  This kind of solution effectively solves the memory and performance problems.
 *  Transformations and Objective operations are, **at minimum**  **O(|S|)**, <b>|S|</b>
 *  being the size of the object used to represent a solution.
 *  If any component of **S** demands more than **O(1)** to be created/evaluated these costs are bigger.
 *  In most cases, create and evaluate *transformations* are **O(1)** on the size of **S**.
 *
 *  Nevertheless, the entanglement of concepts involved in this kind of solution clashes with fundamental
 *  design principles of the framework.
 *
 *  The Onion Framework is structured around components that are
 *
 *  - Uncoupled (independent of each other) by design.
 *  - Associable (may connected to each other) if, and only if, required.
 *  - Simple: Each component **must** have a single and well defined responsibility.
 *  - Extensible and reusable.
 *
 *  Achieve these properties simultaneously demands carefull design and a considerable software engineering effort,
 *  but it results in the virtues we were looking for when we started this work.
 *
 *   - Scalability: new components are added and combined with the existing ones, not recreated.
 *   - Reusable code: abstractions, uncoupling and single responsability results in highly reusable code.
 *   - Reproduction of results: clearly defined components and algorithms make
 *     code interpretation and reproduction much easier.
 *   - Performance attribution: separation of concerns and clear boudaries induced by
 *     components make easier to attrubute and measure performance.
 *
 *  In order to keep the virtues without incurring in the aforementioned problems the Framework introduces a
 *  few "new" concepts and facilities to use these concepts.
 *
 *  They are:
 *
 *  - The **PerturbationParameterOperator:** an operator whose single responsibility is to create a
 *    (possibly unitary) set ofvalid parameters <b>P<sub>i</sub></b> that will be interpreted and evaluated by the
 *  - **DeltaObjective** function: whose single responsibility is to calculate the *difference* in the
 *    value od a solution **S** that results from the application of <b>T(P<sub>i</sub>)</b> on **S**.
 *
 *  In fact, the Perturbation - Objective steps (and its derivatives above) are better understood as a dyad:
 *  two concepts that, altough independent, always work togeter.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef PERTURBATIONPARAMETEROPERATOR_HPP
#define PERTURBATIONPARAMETEROPERATOR_HPP
#include "NonCopyable.hpp"
#include "IdentifiedComponent.hpp"

namespace onion{

/** @class PerturbationParameterOperator
 *  @brief Defines the interface of the PerturbationParameter Operator.
 *  @param solution_t the type used to represent a solution to a problem.
 *  @param perturbation_result_t the type used to represent the result of the perturbation operator.
 *
 *  The concept of a PerturbationParameter operator is explained in detail
 *  <a href="_perturbation_parameter_operator_8hpp.html#PerturbationParameterOperator_BK">here</a>.
 *
 */
template< typename solution_t, typename perturbation_parameter_t >
class PerturbationParameterOperator : public NonCopyable, public IdentifiedComponent
{
public:
    /**
     * @brief Class destructor.
     */
    virtual ~PerturbationParameterOperator() = default;
    /**
     * @brief Creates new perturbation parameters.
     * Parameters must be *valid*: when applied by the corresponding
     * transformation function on a valid solution the result is also a valid solution.
     *
     * Its worth noting that parameters are dependent of problem and independent of
     * particular solutions. Therefore, differently from its sister, PertubationOperator, it
     * does not require a solution object as a parameter.
     * @return A (possibly unitary) set of perturbation parameter objects.
     */
    virtual perturbation_parameter_t operator()() = 0;

};

}


#endif // PERTURBATIONPARAMETEROPERATOR_HPP
