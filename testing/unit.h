#include "../core/defs.h"
#include <cassert>

using test_func = function<void()>;

test_func add_test(str name, test_func func);

#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x,y)

#define REGISTER_TEST(name) test_func CONCAT(__test_, name) = add_test(#name, name)
#define ASSERT(condition) assert(condition)
#define ASSERT_EQ(actual, expected) assert(actual == expected)
