#ifndef TSP_CREATE_RANDOM_HPP
#define TSP_CREATE_RANDOM_HPP

#include "array.hpp"
#include "../../../onion/CreateOperator.hpp"

namespace onion{
namespace cops {
namespace tsp {
namespace array {

// solution_t holds a hamiltonian cycle.
// It is defined to always start at city 0 and has cardinality = num_cities + 1.
// The extra element is used to close the cycle. i.e:
// sol[0] = 0 and sol[ |sol| ] = 0 always
// This makes computations simpler to represent and understand

template<unsigned int num_cities>
class CreateRandom : public onion::CreateOperator< path_t< num_cities > >
{
public:

    CreateRandom():
        Component( SetComponent()
                    .name("CreateRandom")
                    .description("Creates a random hamiltonian cycle.")
                    .type("Create Operator")
                    .version("v0.1.0")
                    .problem("TSP")
                    .solution_type("unsigned int[]")){
    }

    virtual path_t<num_cities> operator()(void){

    }

};

}
}
}
}


#endif
