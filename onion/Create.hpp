#ifndef CREATE_H
#define CREATE_H

/** @file onion/Create.hpp
 *  @brief This header defines the interface of the Create component.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */

#include "Component.hpp"
#include "NonCopyable.hpp"

namespace onion {

template< typename solution_t >
class CreateOperator : public NonCopyable, virtual public Component
{
public:

    CreateOperator() = default;
    virtual ~CreateOperator() = default;

    virtual solution_t operator()(void) = 0;
};

}

#endif
