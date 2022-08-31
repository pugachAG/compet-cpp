#ifndef DSU_SIMPLE_H
#define DSU_SIMPLE_H

#include "../../core/defs.h"
#include "../../utils/vec.h"

struct simple_dsu {
    i32 n;
    vec<i32> p;

    simple_dsu(i32 n): n(n), p(iota(n)) {
    }

    i32 parent(i32 v) {
        if (p[v] != v) {
            p[v] = parent(p[v]);
        }
        return p[v];
    }

    bool join(i32 v, i32 u) {
        i32 pv = parent(v);
        i32 pu = parent(u);
        p[pv] = pu;
        return pu != pv;
    }
};

#endif