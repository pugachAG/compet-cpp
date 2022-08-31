#include "../../core/defs.h"
#include "../../utils/type_traits.h"

/*
struct seg_tree_ops {
    static T combine(T a, T b) {
        return
    }

    static T update(T cur, U val) {
        return
    }
};
 */

template<typename OPS>
class simple_seg_tree {
public:
    using T = return_of_t<decltype(&OPS::combine)>;
    using U = second_arg_of_t<decltype(&OPS::update)>;

    simple_seg_tree(i32 n): _data(4*n), _n(n) {
    }

    simple_seg_tree(const vec<T> &a): simple_seg_tree(a.size()) {
        _bld(a, 1, 0, _n-1);
    }

    T get(i32 l, i32 r) {
        return _get(l, r, 1, 0, _n-1);
    }

    void upd(i32 i, U val) {
        _upd(i, val, 1, 0, _n-1);
    }

private:
    i32 _n;
    vec<T> _data;

    void _bld(const vec<T> &a, i32 v, i32 from, i32 to) {
        if (from == to) {
            _data[v] = a[from];
        } else {
            i32 mid = (from+to)/2;
            _bld(a, 2*v, from, mid);
            _bld(a, 2*v+1, mid+1, to);
            _recalc(v);
        }
    }

    void _upd(i32 i, U val, i32 v, i32 from, i32 to) {
        if (from < to) {
            i32 mid = (from+to)/2;
            if (i <= mid) {
                _upd(i, val, 2*v, from, mid);
            } else {
                _upd(i, val, 2*v+1, mid+1, to);
            }
            _recalc(v);
        } else {
            _data[v] = OPS::update(_data[v], val);
        }
    }

    T _get(i32 l, i32 r, i32 v, i32 from, i32 to) {
        if (l <= from && to <= r) {
            return _data[v];
        }

        i32 mid = (from+to)/2;
        if (l > mid) {
            return _get(l, r, 2*v+1, mid+1, to);
        }
        if (mid+1 > r) {
            return _get(l, r, 2*v, from, mid);
        }
        return OPS::combine(_get(l, r, 2*v, from, mid), _get(l, r, 2*v+1, mid+1, to));
    }

    void _recalc(i32 v) {
        _data[v] = OPS::combine(_data[2*v], _data[2*v+1]);
    }
};