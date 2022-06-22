#ifndef CORE_DEFS_H
#define CORE_DEFS_H

#include "std_includes.h"

using i32 = int;
using i64 = long long;
using str = std::string;

template<typename T>
using vec = std::vector<T>;
template<typename K, typename V>
using map = std::map<K, V>;
template<typename K, typename V>
using hash_map = std::unordered_map<K, V>;
template<typename T>
using set = std::set<T>;
template<typename T>
using hash_set = std::unordered_set<T>;
template<typename T1, typename T2>
using pair = std::pair<T1, T2>;

template<typename T>
using function = std::function<T>;

#endif
