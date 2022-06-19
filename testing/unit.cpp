#include <iostream>
#include "unit.h"

struct test_case {
    str name;
    test_func func;
};

vec<test_case>& tests() {
    static vec<test_case> res = {};
    return res;
}

test_func add_test(str name, test_func func) {
    tests().push_back({name, func});
    return func;
}

i32 main() {
    i32 cnt = tests().size();
    std::cerr << "Executing " << cnt << " tests" << std::endl;
    for (i32 i = 0; i < cnt; i++) {
        auto &tc = tests()[i];
        std::cerr << "Running test #" << i+1 << ": " << tc.name << std::endl;
        tc.func();
    }
}