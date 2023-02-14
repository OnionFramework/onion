#ifndef TSP_CREATE_H
#define TSP_CREATE_H

#include <array>
#include "../../../onion/create.hpp"
#include "../../cop_info.hpp"

namespace onion{
namespace cops {
namespace tsp {
namespace array {

//template<unsigned int sz> using solution_t = std::array<unsigned int,sz>;

//template<unsigned int sz>
//class CreateRandom : public onion::CreateOperator< solution_t<sz> > :
//{
//public:
//    using Base = onion::CreateOperator< solution_t<sz> >;

//    CreateRandom(): Base( COPInfo() = { ClassInfo() = {
//            "CreateRandom",
//            "Creates a random solution to a TSP problem",
//            "v0.1.0" },
//            "TSP",
//            "Any"} ){
//    }

//    virtual solution_t<sz> operator()(void){

//    }
//};

//template<unsigned int sz>
//class CreateGreedy : public onion::CreateOperator< solution_t<sz> >
//{
//public:
//    using Base = onion::CreateOperator< solution_t<sz> >;

//    CreateGreedy(): Base( COPInfo() = { ClassInfo() = {
//            "CreateGreedy",
//            "Creates a solution to a TSP problem.Starts at a random city; next city is chosen as the closest still available.",
//            "v0.1.0"},
//            "TSP",
//            "Any"} ){
//    }

//    virtual solution_t<sz> operator()(void){

//    }
//};

}
}
}
}


#endif
