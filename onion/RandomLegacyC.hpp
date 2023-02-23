/** @file onion/RandomLegacyC.hpp
 *  @brief Implementation of the RandomEngine interface using the legacy C facilities from the C stdlib.
 *  @copyright 2022 André Ladeira/Onion Framework.
 */
#ifndef RANDOMLEGACYC_HPP
#define RANDOMLEGACYC_HPP

#include "onion/RandomEngine.hpp"
#include <cstdlib>
#include <ctime>

namespace onion{

/** @class RandomLegacyC
 *  @brief Implements the RandomEngine interface using legacy C functions from C stdlib.
 *
 *  The random facilities from the C stdlib are known to produce low quality random numbers.
 *  Because of that, this implementation is provided as a convenience only and **should not** be
 *  used as a first option in most cases.
 *
 *  The implementations that use the C++ STL facilities ( RandomSTL ) produce results that are better and,
 *  in many cases, <a href="_random_8hpp.html#perf_comp">faster</a>.
 *
 *  Possible cases where this implementation might be usefull:
 *
 *  - To reproduce and compare results with other applications.
 *  - To test or improve performance, when the quality of the random number it provides is acceptable.
 *
 *  **When is it acceptable?**
 *
 *  Thats a good question I do not know the answer. But I plan to answer it later.
 *
 *  <h3><a id="c_stdlib_non_uniform">Random numbers generated by the C stdlib `rand()` function are not uniform</a></h3>
 *
 *  The `rand()` function from `<cstdlib>` produces random numbers that are not exactly uniform.
 *  Therefore, this implementation also do not produce pseudo-random numbers that are exactly uniformly
 *  distributed in the given intervals.
 *
 *  For more information, please refer to the
 *  <a href="https://cplusplus.com/reference/cstdlib/rand/">rand() function documentation</a>.
 */
class RandomLegacyC final : public RandomEngine{

public:

    /**
     * @brief Class constructor
     */
    RandomLegacyC() noexcept {
        seed(0);
    }
    /**
     * @brief Class destructor
     */
    virtual ~RandomLegacyC() = default;

    /**
     * @brief Implemantation using rand() from `<cstdlib>`
     *
     * This implementation produces results that are slighly non-uniformly distributed.
     * For more details see the [RandomLegacyC class documentation](@ref RandomLegacyC)
     */
    virtual inline int_t uniform_int() noexcept {
        return std::rand();
    }
    /**
     * @brief Implemantation using rand() from `<cstdlib>`
     *
     * This implementation produces results that are slighly non-uniformly distributed.
     * For more details see [the RandomLegacyC class documentation](@ref RandomLegacyC)
     */
    virtual inline int_t uniform_int_between(int_t min, int_t max) noexcept {
        auto range = max-min+1;
        return uniform_int() % range + min;
    }
    /**
     * @brief Implemantation using rand() from `<cstdlib>`
     *
     * This implementation produces results that are slighly non-uniformly distributed.
     * For more details see [the RandomLegacyC class documentation](@ref RandomLegacyC)
     */
    virtual real_t uniform_real_01() noexcept {
        return static_cast<real_t>( std::rand() ) / RAND_MAX ;
    }
    /**
     * @brief Implemantation using srand() and time(nullptr)
     *
     */
    virtual void seed(int_t s = 0) noexcept {
        if (!s)
            std::srand( static_cast<unsigned int>( std::time(nullptr) ) );
        else
            std::srand( static_cast<unsigned int>( s ) );
    }

};

}

#endif // RANDOMLEGACYC_H
