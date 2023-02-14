#ifndef LOCALSEARCH_HPP
#define LOCALSEARCH_HPP

#include <string>

namespace onion{
namespace algorithms{
namespace local_search{

class LocalSearch;

class CreateLocalSearch {

public:

    CreateLocalSearch(const std::string& descr);

    // sets all the default values for each data member
    CreateLocalSearch& setCreateOpertator();
    CreateLocalSearch& setNeighborhoodOperator();
    CreateLocalSearch& setObjectiveFunction();
    CreateLocalSearch& setSelectOperator();
    CreateLocalSearch& setInnerLoopController();
    CreateLocalSearch& setOuterLoopController();

    // ...

private:

    friend class LocalSearch;

};

class LocalSearch {

public:

};

}
}
}
#endif
