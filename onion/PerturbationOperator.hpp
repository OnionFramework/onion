/** @file onion/PerturbationOperator.hpp
 *  @brief This header defines the PerturbationOperator ADT.
 *
 *  **Background**
 *
 *  Consider a solution **S** to a problem. A perturbation operator **P** is defined as an operation that
 *  takes some **S** as a parameter and produces one or more solutions as a result:
 *
 *  <b>P(S) = {S<sub>1</sub>, S<sub>2</sub>, ..., S<sub>n</sub>}, n >= 1 </b>
 *
 *  Each new solution {S<sub>1</sub>,...,S<sub>n</sub>} ∈ P(S*) is the result of a transformation applied to S.
 *
 *  Differences between S<sub>1</sub> ... S<sub>n</sub> are due only to a parameter passed to the transformation.
 *  Thus, we can represent P as the result of a list comprehension:
 *
 *  <b>P(S) = { T(S,P<sub>i</sub>)  | P<sub>i</sub> &isin; {P<sub>1</sub>,P<sub>2</sub>,...,P<sub>n</sub>} }</b>
 *
 *  Because solutions must be valid we can write:
 *
 *  <b>P(S) = { T(S,P<sub>i</sub>)  | P<sub>i</sub> &isin; {P<sub>1</sub>,P<sub>2</sub>,...,P<sub>n</sub>},
 * IsValid( P<sub>i</sub> ) }</b>
 *
 *  Where **IsValid** is a problem-specific validation function.
 *
 *  **In summary**
 *
 *  - Perturbation is an operation that produces new candidate solutions to a problem.
 *  - The solutions produced are both **complete** and **valid**.
 *  - Perturbation produces new solutions by creating small variations in the known solution.
 *  - To create new solutions it uses a fixed procedure called *Transformation*, **T(S,P<sub>i</sub>)**
 *  - <b>T(S,P<sub>i</sub>)</b> is parameterized by some parameter P<sub>i</sub>.
 *  The different solutions produced from the same initial solution are result of the
 *  different values of P<sub>i</sub> passed to **T** ***only***.
 *
 *  **Note:** these remarks clearly define the functional aspects of Perturbation operator in the Onion Franmework context.
 *  It is also used to define its sister concept: the PerturbationParameter operator.
 *
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef PERTURBATIONOPERATOR_HPP
#define PERTURBATIONOPERATOR_HPP

#include "NonCopyable.hpp"
#include "IdentifiedComponent.hpp"

namespace onion{

/** @class PerturbationOperator
 *  @brief Defines the interface of the Perturbation Operator.
 *  @param solution_t the type used to represent a solution to a problem.
 *  @param perturbation_result_t the type used to represent the result of the perturbation operator.
 *
 *  Perturbation is the operator responsible for creating canditate solution to a problem starting from a known solution.
 *  The PerturbationOperator class is an [(ADT)](@ref ABSTRACTDATATYPE) used to represent this
 *  concept and define the protocol of this functionality.
 *
 *  This is one of the fundamental components of the Onion Framework, the others being
 *  the CreateOperator, the ObjectiveFunction and the SelectOperator.
 *
 */
template< typename solution_t, typename perturbation_result_t >
class PerturbationOperator : public NonCopyable, public IdentifiedComponent
{
public:
    /**
     * @brief Class destructor.
     */
    virtual ~PerturbationOperator() = default;
    /**
     * @brief Creates new candidate solutions to a problem. Solutions must be ***complete*** and ***valid***.
     * @param A solution to be perturbed.
     * @return A (possibly unitary) set of solution_t objects.
     */
    virtual perturbation_result_t operator()(const solution_t& ) = 0;

};

}

#endif // PERTURBATIONOPERATOR_H
