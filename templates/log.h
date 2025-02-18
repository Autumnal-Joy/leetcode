//
// Created by Autumnal Joy on 2025/2/18.
//
#include <bits/stdc++.h>

#ifndef LOG_H
#define LOG_H
template<typename T>
void print(const T &x) { std::cerr << x; }

void print(const char &x) { std::cerr << '\'' << x << '\''; }
void print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void print(const char *const &x) { std::cerr << '\"' << x << '\"'; }
void print(const bool &x) { std::cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void print(const std::pair<T, V> &x) {
    std::cerr << "{";
    print(x.first);
    std::cerr << ", ";
    print(x.second);
    std::cerr << "}";
}

template<typename T, typename... Args>
void print(T t, Args... v) {
    print(t);
    std::cerr << ", ";
    print(v...);
}

template<std::ranges::range T>
void print(const T &x) {
    std::cerr << "{";
    int f = 0;
    for (auto &i: x) {
        std::cerr << (f++ ? ", " : "");
        print(i);
    }
    std::cerr << "}";
}

#define dbg(expr...) ([&, __func = __func__] {                   \
auto &&__tmp = (expr);                                       \
auto __val = std::forward<decltype(__tmp)>(__tmp);           \
std::cerr << __func << ":" << __LINE__ << ": (" << #expr << ") = "; \
print(__val);                                                \
std::cerr << endl;                                                \
return __val;                                                \
}())
#endif //LOG_H
