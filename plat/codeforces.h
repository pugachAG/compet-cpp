#include "../core/defs.h"
#include "../core/io.h"
#include "../utils/vec.h"
#include "../utils/iter.h"
#include "../utils/math.h"

/*
Enabling multi-tests:
ENABLE_MULTITEST;
*/

i32 multitest_enalbed = 0;
#define ENABLE_MULTITEST i32 multitest_enalbed_ignore = ++multitest_enalbed


void solve();

i32 main() {
    configure_io();
    if (multitest_enalbed > 0) {
        READ(i32, t);
        for (i32 tc = 0; tc < t; tc++) {
            solve();
        }
    } else {
        solve();
    }
}