/** @file onion/Random.hpp
 *  @brief This header introduces the random number generation (RNG) facilities of the Onion Framework.
 *
 *  ### Context
 *
 *  Random number generation (RNG) during software development is usually quite simple.
 *  Every modern programming language contains at least one built-in library for this purpose.
 *
 *  There are many different algorithms for RNG. However, using different RNG algorithms
 *  in different parts of the same application might the source of a few development headaches:
 *
 *  - **Debugging and result comparisson:** a simple way to compare results from different implementations
 *   of the same algorithm/problem is to run both using the same seed.
 *   If they adopt the same RNG algorithm, the results should be identical.
 *   This simple technique may be impossible to execute if different parts of the code are
 *   implementing RNG independently or using different RNG algorithms.
 *
 *  - **Changing RNG algorithm:** perfomance improvement or comparisson with other implementations
 *  may require changing the RNG algorithm entirely. Without a centralized RNG system, that may be impossible.
 *  Or, at least, a development nigthmare.
 *
 *  From the developer perspective, re-implement the same RNG functionalities is also boring and error prone.
 *
 *  In order to avoid these problems the Onion Framework provides a centralized system for RNG.
 *  It is constituted by the following components:
 *
 *  - **The RandomEngine interface class :** Abstract Data Type that defines the set of available
 *  facilities and their protocol.
 *  - **Built-in RadomEngine implementations :** The framework provides two default implementations
 *   of the RandomEngine interface.
 *   + **RandomLegacyC:** implements RandomEngine using legacy C facilities. Namely: the rand(), time() and
 *   seed() functions from the C standard library.
 *   + **RandomSTL:** implements RandomEngine using the facilities provided by C++ (11 and above) STL.
 *
 *  - **The RandomEngineProxy class:** this class creates the global random engine object and
 *  controls the access to it.
 *
 *  - **The Random() function:** returns the single point of access to the global RandomEngine object.
 *
 *   - **The SetRandomEngine() function:** configures the global RandomEngine object.
 *
 *  The next example shows how to use the RNG system of the Onion Framework.
 *
 *      #include "onion/random.hpp"
 *      ...
 *      // changes the random engine to RandomLegacyC
 *      SetRandomEngine( new RandomLegacyC() );
 *
 *      // gets a random integer in the range [1,10]
 *      auto rndi = Random().uniform_int_between(1,10);
 *
 *      //  gets a random real number in the range [0,1]
 *      auto rndd = Random().uniform_real_01();
 *
 *  <h3><a id="perf_comp">Performance comparisson</a></h3>
 *
 *  The next tables preset performance results of a few different engines as implemented by some compilers.
 *  **Results are presented as time relative to the reference implementation**. A result of 1.5 means that
 *  the implementation is 50% ***slower*** than the reference.
 *
 *  **Reference:** local implementation using C stdlib.<br>
 *  **LegacyC:** Onion implementation using C stdlib.<br>
 *  **STL (LCG):** Linear Congruential Generator `stl::minstd_rand`.
 *  This is the default engine in most STL implementations.<br>
 *  **STL (MT):** STL Mersenne Twister 19937 generator.
 *
 *  Test 1: time to generate 1 million uniformly distributed<sup><a href=#note1>1</a></sup> integers in the range [0,max_int]
 *
 *  | Compiler	                                      | Reference    | Legacy C     | STL (LCG)    | STL (MT)  |
 *  | :----                                           | :----:       | :----:       | :----:       | :---:     |
 *  | g++ (Ubuntu 12.2.0-3ubuntu1) 12.2.0             | 1.00         | 1.08         | 1.52         | 0.68      |
 *  | Apple LLVM version 10.0.0 (clang-1000.11.45.5)  | 1.00         | 1.00         | 1.50         | 1.63      |
 *
 *  Test 2: time to generate 1 million uniformly distributed<sup><a href=#note1>1</a></sup> integers in the range [1,1000]
 *
 *  | Compiler	                                      | Reference    | Legacy C     | STL (LCG)    | STL (MT)  |
 *  | :----                                           | :----:       | :----:       | :----:       | :---:     |
 *  | g++ (Ubuntu 12.2.0-3ubuntu1) 12.2.0             | 1.00         | 1.15         | 0.44         | 0.72      |
 *  | Apple LLVM version 10.0.0 (clang-1000.11.45.5)  | 1.00         | 1.05         | 5.18         | 2.86      |
 *
 *  Test 3: time to generate 1 million uniformly distributed<sup><a href=#note1>1</a></sup> real numbers in the range [0,1]
 *
 *  | Compiler	                                      | Reference    | Legacy C     | STL (LCG)    | STL (MT)  |
 *  | :----                                           | :----:       | :----:       | :----:       | :---:     |
 *  | g++ (Ubuntu 12.2.0-3ubuntu1) 12.2.0             | 1.00         | 1.08         | 0.67         | 1.06      |
 *  | Apple LLVM version 10.0.0 (clang-1000.11.45.5)  | 1.00         | 0.98         | 1.56         | 2.54      |
 *
 *  **Notes**
 *
 *  <a id="note1">1</a>: Reference and Legacy C implementations produce results that
 *  are sligtly <a href="classonion_1_1_random_legacy_c.html#c_stdlib_non_uniform">non uniform</a>.
 *
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "RandomEngine.hpp"
#include "NonCopyable.hpp"

namespace onion{

/** @class RandomEngineProxy
 *  @brief Creates and control the access to the global RandonEngine object.
 *
 *  The Onion Framework recomends that random number generation to be both centralized
 *  and homogeneous, i.e., use a single algorithm. A discussion on this subject is presented
 *  [(here)](@ref onion/Random.hpp).
 *
 *  All RandomEngineProxy methods are private. RNG functionalities are accessed using the
 *  Random() and SetRandomEngine functions.
 *
 */
class RandomEngineProxy final : public NonCopyable{

private:

    /**
     * @brief Returns a reference to the global RandomEngine object.
     *
     */

    static inline RandomEngine& getRandomEngine(){
        return (*_engine);
    }
    /**
     * @brief Sets the global RandomEngine object.
     *
     */
    static inline void setRandomEngine(RandomEngine* newEngine){
        _engine = newEngine;
    }

    friend inline RandomEngine& Random();
    friend inline void SetRandomEngine(RandomEngine* newEngine);
    /**
     * @brief Class constructor.
     *
     * The constructor is private because this class is designed to be used
     * only by the friend fucntions Random and SetRandomEngine.
     *
     */
    RandomEngineProxy() = default;
    /**
     * @brief Global RandomEngine object.
     *
     * This is the pointer to the single global RandomEngine object.
     * By default, it points to an instance of RandomSTL configured with the
     * [std::minstd_rand](@ref https://cplusplus.com/reference/random/minstd_rand/ ) random engine.
     *
     */
    static RandomEngine* _engine;
};

/**
 * @brief Return access point to the global RandomEngine object
 *
 */

inline RandomEngine& Random(){
     static RandomEngineProxy proxy;
     return RandomEngineProxy::getRandomEngine();
}

/**
 * @brief Sets the global RandomEngine object
 *
 */
inline void SetRandomEngine(RandomEngine* newEngine){
     return RandomEngineProxy::setRandomEngine(newEngine);
}

}
#endif // RANDOM_HPP
