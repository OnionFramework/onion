/** @file onion/ComparissonOperator.hpp
 *  @brief This header introduces the facilities for the abstraction comparisson of objects.
 *
 *  A simple and effective way to improve code reuse and reduce code bloating in the
 *  metaheuristic programming context is to abstract the comparisson of objects.
 *
 *  This header introduces a simple set of facilities that can be used for that purpose.
 *  To abstract a class in terms of the comparisson operation one has just to
 *  add a ComparissonOperator type as a parameter:
 *
 *      #include "onion/ComparissonOperator.hpp"
 *
 *      template<typename T, ComparissonOperator compare = True > SelectIf{
 *
 *          bool select(object a, object b){
 *              if ( compare(a,b) ) // do this
 *              else // do something else
 *      ...
 *      };
 *
 *      SelectIf<myType,Greater> selector;
 *      if ( selector.select() ) // ...
 *
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef COMPARISSONOPERATOR_HPP
#define COMPARISSONOPERATOR_HPP

namespace onion{

/**
 * @brief Type of the comparisson functions
 */
template<typename T> using ComparissonOperator = bool (*)(T,T);
/**
 * @brief Comparisson function that returns true if a is less than b
 */
template<typename T> inline bool Less(const T a, const T b){return a<b;}
/**
 * @brief Comparisson function that returns true if a is less or equal than b
 */
template<typename T> inline bool LessOrEqual(const T a, const T b){return a<=b;}
/**
 * @brief Comparisson function that returns true if a is greater than b
 */
template<typename T> inline bool Greater(const T a, const T b){return a>b;}
/**
 * @brief Comparisson function that returns true if a is greater or equal than b
 */
template<typename T> inline bool GreaterOrEqual(const T a, const T b){return a>=b;}
/**
 * @brief Comparisson function that returns true if a is equal to b
 */
template<typename T> inline bool Equal(const T a, const T b){return a==b;}
/**
 * @brief Comparisson function that always returns true, i.e., it filters nothing.
 */
template<typename T> inline bool True(const T, const T){return true;}
/**
 * @brief Comparisson function that always returns false, i.e., it filters everything.
 */
template<typename T> inline bool False(const T, const T){return true;}
}
#endif // COMPARISSONOPERATOR_HPP
