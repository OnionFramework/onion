#ifndef TYPETRAITS_HPP
#define TYPETRAITS_HPP

#include <type_traits>

namespace onion{

template< typename... Ts >
struct make_void { typedef void type; };

template< typename... Ts >
using void_t = typename make_void<Ts...>::type;

template <typename, typename = void>
constexpr bool has_member_at = false;

template <typename T>
constexpr bool has_member_at<T, void_t< decltype(std::declval<T>().at(0))>> = true;

template <typename, typename = void>
constexpr bool has_subscript_operator = false;

template <typename T>
constexpr bool has_subscript_operator<T, void_t< decltype(std::declval<T>().at(0))>> = true;


}

#endif // TYPETRAITS_HPP
