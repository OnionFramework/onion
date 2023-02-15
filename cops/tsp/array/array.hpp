#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <array>

namespace onion{
namespace cops {
namespace tsp {
namespace array {

template<unsigned int num_cities> using solution_t = std::array< unsigned int, num_cities + 1 >;
template<unsigned int sz> using path_t = solution_t<sz>;

}
}
}
}
#endif // ARRAY_HPP
