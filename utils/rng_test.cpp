#include "rng.h"
#include "../testing/unit.h"

vec<i32> _to_vec(rng_container rng) {
    vec<i32> res;
    for (i32 v: rng) {
        res.push_back(v);
    }
    return res;
}

void basic_rng() {
    ASSERT_EQ(_to_vec(rng(1, 3)), vec<i32>({1, 2}));
    ASSERT_EQ(_to_vec(rng(2)), vec<i32>({0, 1}));
    ASSERT_EQ(_to_vec(rng(2, 2)), vec<i32>());
    ASSERT_EQ(_to_vec(rng(3, 2)), vec<i32>());
    ASSERT_EQ(_to_vec(rng_incl(2)), vec<i32>({0, 1, 2}));
    ASSERT_EQ(_to_vec(inv(rng(3))), vec<i32>({2, 1, 0}));
    ASSERT_EQ(_to_vec(inv(rng(3, 2))), vec<i32>());
}


REGISTER_TEST(basic_rng);