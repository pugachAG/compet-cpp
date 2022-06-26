#ifndef MATH__modULO_H
#define MATH__modULO_H

#include "../core/defs.h"

struct modulo_ops {
    modulo_ops(i64 mod): _mod(mod) {
    }

    i64 add(i64 x, i64 y) {
        return (x+y)%_mod;
    }

    i64 subtr(i64 x, i64 y) {
        return (x-y+_mod)%_mod;
    }

    i64 mult(i64 x, i64 y) {
        return ((x%_mod) * (y%_mod)) % _mod;
    }

    i64 div(i64 x, i64 y) {
        assert(y % _mod != 0);
        return mult(x, inv(y));
    }

    i64 pow(i64 x, i64 p) {
        return _pow(x, p, 1);
    }

    i64 inv(i64 x) {
        return pow(x, _mod-2);
    }

private:
    i64 _mod;

    i64 _pow(i64 x, i64 p, i64 res) {
        if (p == 0) {
            return res;
        }
        return _pow(mult(x, x), p/2, mult(res, (p%2 == 0 ? 1 : x)));
    }
};

#endif