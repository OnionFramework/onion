#ifndef COMPARISSONOPERATOR_HPP
#define COMPARISSONOPERATOR_HPP
namespace onion{

template<typename T> using ComparissonOperator = bool (*)(T,T);

template<typename T> inline bool Less(const T a, const T b){return a<b;}
template<typename T> inline bool LessOrEqual(const T a, const T b){return a<=b;}
template<typename T> inline bool Greater(const T a, const T b){return a>b;}
template<typename T> inline bool GreaterOrEqual(const T a, const T b){return a>=b;}
template<typename T> inline bool Equal(const T a, const T b){return a==b;}
template<typename T> inline bool True(const T, const T){return true;}

}
#endif // COMPARISSONOPERATOR_HPP
