#ifndef CORE_HASH_H
#define CORE_HASH_H

#include <functional>
#include <tuple>

// http://stackoverflow.com/questions/4948780
template <class T>
inline void _hash_combine(std::size_t& seed, T const& v) {
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <class TPL, std::size_t IDX = std::tuple_size<TPL>::value - 1>
struct _tuple_hash_impl {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _tuple_hash_impl<TPL, IDX-1>::apply(seed, tuple);
        _hash_combine(seed, std::get<IDX>(tuple));
    }
};

template <class TPL>
struct _tuple_hash_impl<TPL, 0> {
    static void apply(std::size_t& seed, TPL const& tuple) {
        _hash_combine(seed, std::get<0>(tuple));
    }
};

template<typename ... T>
struct std::hash<std::tuple<T...>> {
    std::size_t operator()(std::tuple<T...> const& tuple) const {                                              
        std::size_t seed = 0;                             
        _tuple_hash_impl<std::tuple<T...> >::apply(seed, tuple);    
        return seed;                                 
    }  
};

#endif