#ifndef UTILS_ITER_H
#define UTILS_ITER_H

#include "../core/defs.h"
#include "math.h"

struct rng_container_iterator {
    i32 val;
    i32 dir;

    rng_container_iterator(i32 val, i32 dir): val(val), dir(dir) {
    }

    rng_container_iterator& operator++() {
        val += dir;
        return *this;
    }

    i32 operator*() const {
        return val;
    }

    bool operator==(const rng_container_iterator& other) const {
        return val == other.val;
    }

    bool operator!=(const rng_container_iterator& other) const {
        return val != other.val;
    }
};

struct rng_container {
    i32 start;
    i32 bound;
    i32 dir;

    rng_container_iterator begin() {
        return rng_container_iterator(start, dir);
    }

    rng_container_iterator end() {
        return rng_container_iterator(bound, dir);
    }
};

rng_container rng(i32 start, i32 bound) {
    return {min(start, bound), bound, 1};
}

rng_container rng(i32 bound) {
    return rng(0, bound);
}

rng_container rng_incl(i32 start, i32 bound) {
    return rng(start, bound+1);
}

rng_container rng_incl(i32 bound) {
    return rng_incl(0, bound);
}

rng_container inf_rng() {
    return rng(2e9);
}

rng_container rev(rng_container range) {
    return {range.bound-1, range.start-1, -1};
}

template<typename T>
rng_container indices(const vec<T> &a) {
    return rng(a.size());
}

#endif