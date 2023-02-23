/** @file onion/RandomEngine.hpp
 *  @brief Declaration of the RandomEngine interface.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef RANDOMENGINE_HPP
#define RANDOMENGINE_HPP

namespace onion{

/** @class RandomEngine
 *  @brief Inteface class for random number generation.
 *
 *  RandomEngine is an interface class (an Abstract Data Type) that defines the set
 *  of functionalities that constiture a radom number generator (RNG) engine
 *  in the Onion Franmework contecxt.
 *
 */
class RandomEngine{

public:
    using int_t = unsigned int;
    using real_t = double;

    /**
     * @brief Method to return a pseudo-random integer.
     *
     * RandomEngine implementations must return a *uniformily distributed* pseudo random integer
     * in the range of the integer type used. The size of default integer type (`unsigned int`) is 32 bits
     * in most modern machines. This results in a range  of `[ 0 , uint_max ]` where
     * uint_max = (2^32) - 1 = 2,147,483,647
     */
    virtual int_t uniform_int() noexcept = 0;
    /**
     * @brief Method to return a pseudo-random integer in the [*min*,*max*] interval.
     * @param min the lower limit of the interval.
     * @param max the upper limit of the interval.
     *
     * RandomEngine implementations must return a *uniformily distributed* pseudo-random integer
     * in the range [min,max].
     */
    virtual int_t uniform_int_between(int_t min, int_t max) noexcept = 0;
    /**
     * @brief Method to return a real number between 0 and 1.
     *
     * RandomEngine implementations must return a *uniformily distributed* real number in the range [0,1]
     *
     */
    virtual real_t uniform_real_01() noexcept = 0;
    /**
     * @brief Interface method to implement the seed mechanism.
     * @param s the seed value, default 0.
     *
     * The behaviour of the seed function depends on the seed provided:
     *
     * - If no value (default) or zero is provided, implementations shoud use some
     *  *high-resolution* seeding mechanism, like a high-resolution clock.
     *
     * - If any value other than zero is provided it is used the seed. Deterministic seeds
     * can be used to produce a expected result in a debug or test routine, for example.
     *
     *  *Why it should be high resolution?*
     * Because different pseudo-random number sequences may be required within a very
     * short time intervals. If the seed generation method is not refined enough, it
     * come up with the same seed if called twice in that interval.
     *
     */
    virtual void seed(int_t s = 0) noexcept = 0;

protected:

    friend class RandomEngineProxy;

    /**
     * @brief Class constructor
     */
    RandomEngine() = default;
    /**
     * @brief Class destructor
     */
    virtual ~RandomEngine() = default;

};

}


#endif // RANDOM_HPP
