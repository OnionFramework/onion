#ifndef TSP_CREATE_H
#define TSP_CREATE_H

#include <array>
#include "../../../onion/create.hpp"

namespace onion{
namespace cops {
namespace tsp {
namespace array {

template<unsigned int sz> using solution_t = std::array<unsigned int,sz>;

template<unsigned int sz>
class CreateRandom : public onion::CreateOperator< solution_t<sz> >
{
public:

    CreateRandom():Component( SetComponent()
                                .name("CreateRandom")
                                .description("Creates a random hamiltonian cycle.")
                                .type("Create Operator")
                                .version("v0.1.0")
                                .problem("TSP")
                                .solution_type("unsigned int[]")){
    }

    virtual solution_t<sz> operator()(void){

    }

};

template<unsigned int sz>
class CreateGreedy : public onion::CreateOperator< solution_t<sz> >
{
public:

    CreateGreedy(): Component( SetComponent()
                               .name("CreateGreedy")
                               .description("Starts at a random city then move to the closest city recursively until all cities are visited.")
                               .type("Create Operator")
                               .version("v0.1.0")
                               .problem("TSP")
                               .solution_type("unsigned int[]")){}

    virtual solution_t<sz> operator()(void){

    }

};

}
}
}
}


#endif
