#ifndef UTILS_ITER_H
#define UTILS_ITER_H

#include "../core/defs.h"

struct rng_iterator {
    i32 val;

    rng_iterator(i32 val): val(val) {
    }

    rng_iterator& operator++() {
        val++;
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

    rng(i32 start, i32 bound): start(start), bound(bound) {
    }

    rng(i32 bound): rng(0, bound) {
    }

    rng_iterator begin() {
        return rng_iterator(start);
    }

    rng_iterator end() {
        return rng_iterator(bound);
    }
};

#endif