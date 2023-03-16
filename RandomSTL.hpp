/** @file onion/RandomSTL.hpp
 *  @brief Implementation of the RandomEngine interface using C++11 (and above) RNG facilities.
 *
 *  This file contains the definition of the RandomSTL class.
 *  This class contains the implementation of the Random interface
 *  using the random number generation facilities provided by the
 *  C++ Standard Template Library (STL) available in C++, versions
 *  11 and above.
 *
 */
#ifndef RANDOMSTL_HPP
#define RANDOMSTL_HPP

#include "RandomEngine.hpp"
#include <random>

namespace onion{

/** @class RandomSTL
 *  @brief Implements the RandomEngine interface using the C++ STL facilities.
 *  @param random_engine_t STL class used as the random number generator.
 *
 *  *Note* the random_engine is a template parameter because the STL does not
 *  structure its random engine classes on top of a commom base class.
 *  In other words: altough STL random engines do implement the same
 *  functions (what make it possible using them as template parameters),
 *  they do not share a base class and are not polymorphic objects.
 */
template< class random_engine_t = std::minstd_rand >
class RandomSTL final : public RandomEngine{

public:
    /**
     * @brief Class constructor
     */
    RandomSTL() noexcept {
        seed();
    }
    /**
     * @brief Class destructor
     */
    virtual ~RandomSTL() = default;
    /**
     * @brief Implemantation using STL uniform_int_distribution<>`
     *
     */
    virtual inline int_t uniform_int() noexcept {
        return std::uniform_int_distribution<int_t>()(random_engine);
    }
    /**
     * @brief Implemantation using STL uniform_int_distribution<>`
     *
     */
    virtual inline int_t uniform_int_between(int_t min, int_t max) noexcept {
        return std::uniform_int_distribution<int_t>(min,max)(random_engine);
    }
    /**
     * @brief Implemantation using STL uniform_real_distribution<>`
     *
     */
    virtual inline real_t uniform_real_01() noexcept {
        return std::uniform_real_distribution<real_t>(0.0,1.0)(random_engine);
    }
    /**
     * @brief Implemantation of seed() using the given STL engine seed() function.
     *
     * This implementation uses the `std::random_device` class as the
     * high resolution seeding mechanism.
     */
    virtual void seed(int_t s = 0) noexcept {
        if (!s){
            std::random_device r;
            random_engine.seed( r() );
        }
        else{
            random_engine.seed(0);
        }
    }

private:

    random_engine_t random_engine;

};

}

#endif // RANDOMSTL_H
