#include "../core/defs.h"
#include "../core/io.h"
#include "../utils/vec.h"
#include "../utils/rng.h"
#include "../utils/containers.h"
#include "../utils/math.h"
#include "../utils/dataclass.h"

/*
Enabling multi-tests:
ENABLE_MULTITEST;
*/

i32 multitest_enalbed = 0;
#define ENABLE_MULTITEST i32 multitest_enalbed_ignore = ++multitest_enalbed

void println_yes_no(bool ans) {
    println(ans ? "Yes" : "No");
}

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