/** @file onion/ParameterOperator.hpp
 *  @brief This header has the definition of the CreateOperator component.
 *
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef PARAMETEROPERATOR_HPP
#define PARAMETEROPERATOR_HPP
#include "NonCopyable.hpp"
#include "ComponentID.hpp"

namespace onion{

/** @class ParameterOperator
 *  @brief Abstract Data Type that defines the ParameterOperator component.
 *  @param solution_t type of the compact representation of a solution to the problem.
 *  @param perturbation_result_t the type of the results created by the perturbation operator.
 *
 *  ParameterOperator objects are responsible for creating valid transformation parameters.
 *  These parameters are used later by a DeltaObjective function to evaluate
 *  potential solutions.
 *
 *  The ParameterOperator is, along with the DeltaObjective function, one of the
 *  <a href="./md__glossary.html#adt">delta components</a> of the Onion Framework.
 *
 * @note ParameterOperator is an <a href="./md__glossary.html#adt">Abstract Data Type</a>.
 *  It means it provides no functionality and can't be instantiated.
 *  Instead, its purpose is to define unambiguously what "ParameterOperator" does in the
 *  framewok's context.
 *  Actual functionality will be defined later by concrete implementions in derived classes.
 *
 *  <h2><a id="ParameterOperator_bk">Background</a></h2>
 *
 *  A regular
 *  <a href="./classonion_1_1_perturbation_operator.html#PerturbationOperator_bk">Perturbation operator</a>
 *  receives a solution to a problem and returns a set of new candidate solutions.
 *  These solutions must be, by definition, **valid** and **complete**.
 *
 *  However, there are many cases when its not possible to work with complete solutions.
 *  So far, we've identified two typical situations where it happens:
 *
 *  1. Individual solutions are too expensive to create and/or process.
 *  For example: each solutions of the <a href="https://cs.uef.fi/sipu/santa/">Santa Claus TSP Challenge</a>
 *  are arrays with ~1.5 million integers.
 *  2. The algorithm used in the perturbation return too many solutions.
 *  Example: 2-opt algorithm for TSP problems creates O(n<sup>2</sup>) solutions, where n is the number
 *  of cities or stops. This becomes unmanageable even at modest problem sizes, n ~ 1000;
 *
 *  Typically, in these cases algorithms perform perturbation, evaluation and
 *  selection in the same procedure, one solution at a time. Moreover, solutions
 *  are not created. Instead, a procedure devises ***transformation paramaters***.
 *  The value of the ***potential solution*** that would be created by a transformation,
 *  using that parameter is determined by a ***DeltaObjective*** function:
 *
 *  <b>v<sub>i</sub> = v + Δ( S, P<sub>i</sub> )</b>
 *
 *  where,
 *
 *  <b>v<sub>i</sub></b>   : value of the ith candidate solution.<br>
 *  <b>v   : value of the current solution.<br>
 *  <b>S</b>   : current solution.<br>
 *  <b>P<sub>i</sub></b>    : ith parameter produced by a Parameter operator.<br>
 *  <b>Δ(S,P<sub>i</sub>)</b>   : Delta objective function.<br>
 *
 *  <div class="info">
 *  The **Δ** function is very similar to the ObjectiveFunction, with the difference that it
 *  does not calculate the value of a solution but rather the difference in this value
 *  caused by some transformation **τ** using the parameter P<sub>i</sub>.
 *  For this reason we called it **DeltaObjective** function.
 *  </div>
 *
 *  <h2>Costs</h2>
 *
 *  Transformations and ObjectiveFunction calls costs are, **at minimum**, proportinonal to the
 *  size of the solution object, <b>|S|</b>:
 *
 *  <b>C( P(S) ) = C( T(S,P<sub>i</sub>) ) = Ω(|S|)</b>.
 *
 *  **C** is the cost function and <i>f(x) = Ω( g(y) )</i> is the big *O* notation for a function *f*
 *  that is bounded below by *g*.
 *
 *  On the other hand, **transformations** and **DeltaObjective** functions are, in most cases, **O(1)**.
 *
 *  <h2>'Delta' components of the Onion Framework</h2>
 *
 *  The solution outlined above solves the performance and memory usage issues caused by
 *  creating and processing complete solutions. However, it is structured in a way that clashes with the
 *  <a href="">design principles</a> of the Onion Framework. Fundamentally, it mixes three components
 *  into a single one and that breakes the component model completely, with the
 *  <a href="">well known consequences</a>.
 *
 *  In order to keep the virtues of that solution without breaking the component model, the Framework introduces a
 *  few "new" concepts.
 *
 *  They are:
 *
 *  - The **ParameterOperator:** an operator whose single responsibility is to create a
 *    (possibly unitary) set of valid parameters <b>P<sub>i</sub></b> that will be passed to the
 *
 *  - **DeltaObjective** function: whose single responsibility is to calculate the *difference* in the
 *    value of a solution **S** that results from the application of a transformation
 *    <b>τ(P<sub>i</sub>)</b> on **S**.
 *
 *  In fact, the Perturbation - Objective steps (and its derivatives above) are better understood as a dyad:
 *  two concepts that, altough independent, always work togeter.
 *
 */
template< typename solution_t, typename parameter_t >
class ParameterOperator : public NonCopyable, public ComponentID
{
public:
    /**
     * @brief Class destructor.
     */
    virtual ~ParameterOperator() = default;
    /**
     * @brief Creates new perturbation parameters.
     * Parameters must be *valid*: when applied by the corresponding
     * DeltaObjective function on a valid solution the result is also a valid solution.
     *
     * Its worth noting that parameters are dependent of problem and independent of
     * particular solutions. Therefore, differently from its sister, PertubationOperator, it
     * does not require a solution object as a parameter.
     *
     * @return A (possibly unitary) set of perturbation parameter objects.
     */
    virtual parameter_t operator()() = 0;

};

}


#endif // PERTURBATIONPARAMETEROPERATOR_HPP
