#include "../core/defs.h"

template<typename T>
T pop_back(vec<T> &a) {
    auto v = a.back();
    a.pop_back();
    return v;
}

template<typename T, typename CONT, typename CMP>
T pop(std::priority_queue<T, CONT, CMP> &q) {
    auto res = q.top();
    q.pop();
    return res;
}