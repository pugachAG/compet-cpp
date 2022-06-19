#include "../core/defs.h"

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> min(T1 v1, T2 v2) {
    return v1 < v2 ? v1 : v2;
}

template<class T1, class T2, class T3>
constexpr std::common_type_t<T1, T2, T3> min(T1 v1, T2 v2, T3 v3) {
    return min(v1, min(v2, v3));
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> max(T1 v1, T2 v2) {
    return v1 > v2 ? v1 : v2;
}

template<class T1, class T2, class T3>
constexpr std::common_type_t<T1, T2, T3> max(T1 v1, T2 v2, T3 v3) {
    return max(v1, max(v2, v3));
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> gcd(T1 v1, T2 v2) {
    return std::gcd(v1, v2);
}

template<class T1, class T2>
constexpr std::common_type_t<T1, T2> lcm(T1 v1, T2 v2) {
    return std::lcm(v1, v2);
}

/*
template<typename T, typename... Args>
void min(T v, Args... args) {
    os << v << " ";
    _write(os, args...);
}
*/