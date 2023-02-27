#ifndef SELECTOPERATOR_HPP
#define SELECTOPERATOR_HPP

#include "ComponentID.hpp"
#include "NonCopyable.hpp"
#include "ComparissonOperator.hpp"

namespace onion{



template< typename objective_measure_t,
          typename objective_function_result_t,
          typename ComparissonOperator = Less<objective_measure_t> >
class SelectOperator : public NonCopyable, public ComponentID
{
public:
    virtual ~SelectOperator() = default;
    virtual  AcceptResult operator()(const objective_measure_t& best_sofar,
                                     const objective_function_result_t& candidates) = 0;

};

}


#endif // SELECTOPERATOR_H
