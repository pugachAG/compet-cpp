#ifndef UTILS_ITER_H
#define UTILS_ITER_H

#include "../core/defs.h"

struct rng_iterator {
    i32 val;
    i32 dir;

    rng_iterator(i32 val, i32 dir): val(val), dir(dir) {
    }

    rng_iterator& operator++() {
        val += dir;
        return *this;
    }

    i32 operator*() const {
        return val;
    }

    bool operator==(const rng_iterator& other) const {
        return val == other.val;
    }

    bool operator!=(const rng_iterator& other) const {
        return val != other.val;
    }
};

struct rng {
    i32 start;
    i32 bound;
    i32 dir;

    rng(i32 v1, i32 v2) {
        if (v2 >= v1) {
            start = v1;
            bound = v2;
            dir = 1;
        } else {
            start = v1-1;
            bound = v2-1;
            dir = -1;
        }
    }

    rng(i32 bound): rng(0, bound) {
        assert(bound >= 0);
    }

    rng_iterator begin() {
        return rng_iterator(start, dir);
    }

    rng_iterator end() {
        return rng_iterator(bound, dir);
    }
};

#endif