#ifndef CORE_IO_H
#define CORE_IO_H

#include "std_includes.h"
#include <iostream>
#include <fstream> 
#include <type_traits>

std::istream *in;
std::ostream *out;

void enable_fast_input() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

void flush_out() {
    out->flush();
}

void configure_io() {
    auto is_local = getenv("LOCAL");
    if (is_local) {
        auto ifs = new std::ifstream();
        ifs->open("input.txt", std::ifstream::in);
        in = ifs;
        auto ofs = new std::ofstream();
        ofs->open("out/output.txt", std::ofstream::out);
        out = ofs;
        atexit(flush_out);
    } else {
        in = &std::cin;
        out = &std::cout;
        enable_fast_input();
    }
}

template<typename T>
T read() {
    T res;
    *in >> res;
    return res;
}

template<typename T>
std::vector<T> read_vec(int sz) {
    std::vector<T> res(sz);
    for (auto i = 0; i < sz; i++) {
        res[i] = read<T>();
    }
    return res;
}

#define READ_1(tp, var) tp var = read<tp>()
#define READ_2(tp, var_1, var_2) READ_1(tp, var_1); READ_1(tp, var_2)
#define READ_3(tp, var_1, var_2, var_3) READ_2(tp, var_1, var_2); READ_1(tp, var_3)
#define READ_4(tp, var_1, var_2, var_3, var_4) READ_3(tp, var_1, var_2, var_3); READ_1(tp, var_4)
#define READ_5(tp, var_1, var_2, var_3, var_4, var_5) READ_4(tp, var_1, var_2, var_3, var_4); READ_1(tp, var_5)
#define _GET_READ_NAME(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define READ(...) _GET_READ_NAME(__VA_ARGS__, READ_5, READ_4, READ_3, READ_2, READ_1)(__VA_ARGS__)
#define READ_VEC(tp, var, sz) std::vector<tp> var = read_vec<tp>(sz)

void _println() {
    *out << "\n";
}

template<typename T>
void _write(std::ostream &os, const T &v) {
    os << v;
}

template<typename T>
void _write(std::ostream &os, const std::vector<T> &a) {
    for (auto i = 0; i < a.size(); i++) {
        if (i > 0) {
            os << " ";
        }
        os << a[i];
    }
}

template<typename T, typename... Args>
void _write(std::ostream &os, const T &v, Args... args) {
    os << v << " ";
    _write(os, args...);
}

void _writeln(std::ostream &os) {
    os << "\n";
}

template<typename T, typename... Args>
void _writeln(std::ostream &os, const T &v, Args... args) {
    _write(os, v, args...);
    _writeln(os);
}

template<typename... Args>
void println(Args... args) {
    _writeln(*out, args...);
}

#endif