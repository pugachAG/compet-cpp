#include "../core/defs.h"

#include <random>

std::mt19937 _gen;

i32 gen_i32(i32 mn, i32 mx) {
    std::uniform_int_distribution<> distrib(mn, mx);
    return distrib(_gen);
}

i32 gen_i32(i32 mx) {
    return gen_i32(0, mx);
}

vec<i32> gen_i32_vec(i32 n, i32 mn, i32 mx) {
    std::uniform_int_distribution<> distrib(mn, mx);
    vec<i32> a(n);
    for (auto &v: a) {
        v = distrib(_gen);
    }
    return a;
}