#ifndef CREATE_HPP
#define CREATE_HPP

#include "component.hpp"
#include "non_copyable.hpp"

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
