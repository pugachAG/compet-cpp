#include "../testing/unit.h"
#include "modulo.h"

void basic_modulo_ops() {
    modulo_ops ops(7);
    ASSERT_EQ(ops.add(5, 4), 2);
    ASSERT_EQ(ops.subtr(4, 6), 5);
    ASSERT_EQ(ops.mult(4, 6), 3);
    ASSERT_EQ(ops.pow(2, 5), 4);
    ASSERT_EQ(ops.inv(5), 3);
    ASSERT_EQ(ops.div(6, 3), 2);
    ASSERT_EQ(ops.div(6, 2), 3);
    ASSERT_EQ(ops.div(6, 1), 6);
}

REGISTER_TEST(basic_modulo_ops);