/** @file onion/CreateOperator.hpp
 *  @brief This header defines the interface of the Create component.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef CREATEOPERATOR_H
#define CREATEOPERATOR_H

#include "IdentifiedComponent.hpp"
#include "NonCopyable.hpp"

namespace onion{

/** @class CreateOperator
 *  @brief Defines the interface of the Create Operator.
 *  @param solution_t the type used to represent a solution to a problem.
 *
 *  Create is the operator responsible for creating a valid solution to a problem.
 *  The CreateOperator class is an [ADT](@ref ABSTRACTDATATYPE) used to represent this
 *  concept and define the protocol of this functionality.
 *
 *  This is one of the fundamental components of the Onion Framework, the others being
 *  the PerturbationOperator, the ObjectiveFunction and the SelectOperator.
 *
 */
template< typename solution_t > class CreateOperator : public NonCopyable, public IdentifiedComponent
{
public:
    /**
     * @brief Class destructor.
     *
     */
    virtual ~CreateOperator() = default;
    /**
     * @brief Creates a valid solution to a problem.
     * @return An instance of solution_t that contains a valid solution to a problem.
     */
    virtual solution_t operator()(void) = 0;
};

}

#endif
