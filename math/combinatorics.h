#include "modulo.h"

struct combinatorics {
    combinatorics(modulo_ops ops): _ops(ops) {
    }

    combinatorics(i64 mod): _ops(mod) {
    }

    i64 combinations(i32 n, i32 k) {
        assert(n >= k);
        return _ops.div(
            fact(n),
            _ops.mult(fact(k), fact(n-k))
        );
    }

    i64 fact(i32 n) {
        while (_fact_mem.size() <= n) {
            i32 sz = _fact_mem.size();
            _fact_mem.push_back(_ops.mult(_fact_mem.back(), sz));
        }
        return _fact_mem[n];
    }
private:
    modulo_ops _ops;
    vec<i64> _fact_mem = {1};
};