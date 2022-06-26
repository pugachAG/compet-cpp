#include "../core/defs.h"

template<typename T>
void sort(vec<T> &a) {
    std::sort(a.begin(), a.end());
}

template<typename T>
vec<T> sorted(const vec<T> &a) {
    auto b = a;
    sort(b);
    return b;
}

template<typename T>
void reverse(vec<T> &a) {
    std::reverse(a.begin(), a.end());
}

template<typename T>
vec<T> reversed(const vec<T> &a) {
    auto b = a;
    reverse(b);
    return b;
}

template<typename T, typename F>
vec<vec<T>> group_consec(const vec<T> &a, F take) {
    i32 sz = a.size();
    vec<vec<T>> res;
    vec<T> cur = {a[0]};
    for (auto i = 1; i < sz; i++) {
        if (!take(cur.back(), a[i])) {
            res.push_back(move(cur));
            cur = {};
        }
        cur.push_back(a[i]);
    }
    res.push_back(move(cur));
    return res;
}