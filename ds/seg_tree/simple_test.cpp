#include "../../testing/unit.h"
#include "simple.h"

struct sum_inc_ops {
    static i32 combine(i32 a, i32 b) {
        return a + b;
    }

    static i32 update(i32 cur, i32 val) {
        return cur + val;
    }
};

void basic_test() {
    vec<i32> a = {1, 2, 3, 4};
    simple_seg_tree<sum_inc_ops> st(a);
    ASSERT_EQ(st.get(0, 1), 3);
    ASSERT_EQ(st.get(2, 2), 3);
    ASSERT_EQ(st.get(0, 3), 10);
    // 1 5 3 4
    st.upd(1, 3);
    ASSERT_EQ(st.get(0, 2), 9);
    ASSERT_EQ(st.get(1, 3), 12);
    // 1 5 4 6
    st.upd(2, 1);
    st.upd(3, 2);
    ASSERT_EQ(st.get(0, 3), 16);
}

REGISTER_TEST(basic_test);
