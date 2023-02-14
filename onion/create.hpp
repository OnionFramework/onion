#ifndef CREATE_HPP
#define CREATE_HPP

#include "class_info.hpp"
#include "non_copyable.hpp"

namespace onion {

template< typename solution_t >
class CreateOperator : virtual public NonCopyable, public ClassInfo
{
public:

    CreateOperator(const ClassInfo& ci):ClassInfo(ci){}
    virtual ~CreateOperator() = default;

    virtual solution_t operator()(void) = 0;
};

}

#endif
