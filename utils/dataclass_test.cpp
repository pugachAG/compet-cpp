#include "../testing/unit.h"
#include "dataclass.h"

DATACLASS(single_val, i32, val);
DATACLASS(point, i32, x, i32, y);

void dataclass_init() {
    single_val v1(42);
    point p(1, 2);
    ASSERT_EQ(p.x, 1);
    ASSERT_EQ(p.y, 2);
}

void dataclass_operators() {
    ASSERT(point(1, 2) == point(1, 2));
    ASSERT(point(1, 2) != point(2, 1));
    ASSERT_EQ(point(1, 2) < point(0, 3), false);
    ASSERT_EQ(point(1, 2) < point(1, 1), false);
    ASSERT_EQ(point(1, 2) < point(2, 1), true);
    ASSERT_EQ(point(1, 2) < point(1, 3), true);
    ASSERT_EQ(point(1, 2) < point(1, 2), false);
}

void dataclass_set() {
    set<point> s = {point(0, 0), point(0, 1), point(1, 0), point(1, 1)};
    ASSERT_EQ(s.count(point(1, 0)), 1);
    ASSERT_EQ(*s.begin(), point(0, 0));
    ASSERT_EQ(*s.rbegin(), point(1, 1));
    ASSERT_EQ(s.count(point(2, 2)), 0);
    s.insert(point(2, 2));
    ASSERT_EQ(s.count(point(2, 2)), 1);
    s.erase(point(2, 2));
    ASSERT_EQ(s.count(point(2, 2)), 0);
}

REGISTER_TEST(dataclass_init);
REGISTER_TEST(dataclass_operators);
REGISTER_TEST(dataclass_set);