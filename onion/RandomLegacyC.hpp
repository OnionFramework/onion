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
 *  The `rand()` function from `<cstdlib>` produces random numbers that are not exactly uniform.
 *  Therefore, the uniform_* functions of this implementation also do not produce
 *  pseudo-random numbers that are exactly uniformly distributed in the given intervals.
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
