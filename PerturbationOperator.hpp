/** @file onion/PerturbationOperator.hpp
 *  @brief This header has the definition the PerturbationOperator Abstract Data type.
 *
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef PERTURBATIONOPERATOR_HPP
#define PERTURBATIONOPERATOR_HPP

#include "NonCopyable.hpp"
#include "ComponentID.hpp"

namespace onion{

/** @class PerturbationOperator
 *  @brief Abstract Data Type that defines the Perturbation Operator.
 *  @param solution_t the type used to represent a solution to a problem.
 *  @param perturbation_result_t the type used to represent the result of the perturbation operation.
 *
 *  PerturbationOperator objects create new solutions to a problem by performing small modifications in
 *  a known solution.
 *
 *  The PerturbationOperator is the engine of an algorithm. It illuminates the close vicinity
 *  of a solution in the search for better alternatives. Thats why it is also called
 *  Neighborhood function or Neighborhood operator by many authors.
 *
 *  @note
 *  PerturbationOperator is an <a href="./md__glossary.html#abstract_data_type">Abstract Data Type</a>.
 *  It means it provides no functionality and can't be instantiated.
 *  Instead, its purpose is to define unambiguously what "Perturbation" means in the framewok's context.
 *  Actual functionality will be defined later by concrete implementions in derived classes.
 *
 *  <h2><a id="perturb_op_bk">Background</a></h2>
 *
 *  Consider a solution **S** to a problem. A perturbation **P** is defined as an operation that
 *  takes some solution **S** as a parameter and produces one or new solutions as a result:
 *
 *  <b>Perturb(S) = {S<sub>1</sub>, S<sub>2</sub>, ..., S<sub>n</sub>}, n >= 1 </b>
 *
 *  Each new solution is the result of a small *transformation*, **τ**,  of the original solution.
 *  Each **τ** is a fixed and simple procedure that always does the same thing. For
 *  example, the 2-opt algorithm thats used to create new candidate solutions in the
 *  <a href="md__glossary.html#tsp">Traveling Salesman Problem (TSP)</a>.
 *  It is a paremeterized **τ** procedure that receives a start position, *s*,  and a length, *l* and
 *  reverses part of a hamiltonian cycle, from *s* to *l*.
 *
 *  Different solutions are, *by definition*, only the result of different parameters passed to the **τ**.
 *  With that in mind we can write
 *
 *  <b>S<sub>i</sub> = τ(S,p<sub>i</sub>), {1 ≤ i ≤ n}</b>.
 *
 *  where <b>p<sub>i</sub></b> is the i<sub>th</sub> set of parameters passed to **τ**.
 *
 *  We can represent **P** in a compact form as the result of a list comprehension:
 *
 *  <b>P(S) = { τ(S,p<sub>i</sub>)  | p<sub>i</sub> &isin; {p<sub>1</sub>,...,p<sub>n</sub>} }</b>
 *
 *  Because solutions must also be valid we can write:
 *
 *  <b>P(S) = { τ(S,p<sub>i</sub>)  | p<sub>i</sub> &isin; {p<sub>1</sub>,...,p<sub>n</sub>},
 *  IsValid( τ(,p<sub>i</sub>) }</b>.
 *
 *  Where **IsValid** is a problem-specific validation function.
 *
 *  @remark
 *  1. Perturbation is an operation that produces new candidate solutions to a problem
 *    by creating small variations in known solutions.
 *  2. The solutions are required to be both **complete** and **valid**.
 *    **Perturbations** must satisfy the same requirements as CreateOperators.
 *  3. To create new solutions it uses a fixed and simple procedure called ***Transformation***,
 *    <b>τ(S,p<sub>i</sub>)</b>.
 *  4. <b>τ(S,p<sub>i</sub>)</b> is always parameterized by some set of parameters <b>p<sub>i</sub></b>,
 *  except, possibly, in the special case when it returns a single solution.
 *  5. Different solutions created by <b>τ(S,p<sub>i</sub>)</b> can ***only*** be the result of
 *  different values of **p<sub>i</sub>** passed to it.
 *
 *  @attention Definition #5 implies that any PerturbationOperator can implement one and only one transformation.
 *  However, many algorithms do use more than one perturbation. The classical examples are the
 *  <a href="md__glossary.html#vna">Variable Neighborhood Algorithms</a>.
 *  In these cases, in order to preserve the Framework's component model,
 *  <b>each different perturbation <i>must</i> be implemented as a separate component.</b>
 *
 *  This completes the definition of Perturbation operator in the Onion Franmework context. It is
 *  also the base to define its sister concept: the ParameterOperator.
 *
 */
template< typename solution_t, typename perturbation_result_t >
class PerturbationOperator : public NonCopyable, public ComponentID
{
public:
    /**
     * @brief Class destructor.
     */
    virtual ~PerturbationOperator() = default;
    /**
     * @brief Creates new candidate solutions to a problem.
     * Solutions must be ***complete*** and ***valid***.
     * @param S a solution. This is the starting point from wich new candidate solutions will be created.
     * @return A (possibly unitary) set of solution objects.
     */
    virtual perturbation_result_t operator()(const solution_t& S) = 0;

};

}

#endif // PERTURBATIONOPERATOR_H
