/** @file onion/CreateOperator.hpp
 *  @brief This header contains the definition of the CreateOperator component.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef CREATEOPERATOR_H
#define CREATEOPERATOR_H

#include "ComponentID.hpp"
#include "NonCopyable.hpp"

namespace onion{

/** @class CreateOperator
 *  @brief Abstract Data Type that defines the CreateOperator component.
 *  @param solution_t the type used to represent a solution to a problem.
 *
 *  The CreateOperator is one of the four fundamental components of the Onion Framework.
 *  The others are the PerturbationOperator, the ObjectiveFunction and the SelectOperator.
 *
 *  The CreateOperator is the easiest component to define: its purpose is ***to create
 *  a solution to the problem of interest***. Period.
 *
 *  However, the solutions it creates must be:
 *
 *  - **Complete:** all its components are set and ready to be used elsewhere.
 *  - **Valid:** any necessary validation is already performed. The solution is correct.
 *
 *  @note
 *  CreateOperator is an <a href="./md__glossary.html#abstract_data_type">Abstract Data Type</a>.
 *  It means it provides no functionality and can't be instantiated.
 *  Instead, its purpose is to define unambiguously what "Create" means in the framewok's context.
 *  Actual functionality will be defined later by concrete implementions in derived classes.
 *
 */
template< typename solution_t > class CreateOperator : public NonCopyable, public ComponentID
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
