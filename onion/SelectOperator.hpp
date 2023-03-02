#ifndef SELECTOPERATOR_HPP
#define SELECTOPERATOR_HPP

#include "IdentifiedComponent.hpp"
#include "NonCopyable.hpp"
#include "ComparissonOperator.hpp"

namespace onion{



template< typename objective_measure_t,
          typename objective_function_result_t,
          ComparissonOperator<objective_measure_t> compare >
class SelectOperator : public NonCopyable, public ComponentID
{
public:
    virtual ~SelectOperator() = default;
    virtual  void operator()(const objective_measure_t& best_sofar,
                                       const objective_function_result_t& candidates) = 0;

};

}


#endif // SELECTOPERATOR_H
