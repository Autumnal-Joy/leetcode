//
// Created by Autumnal Joy on 2025/2/18.
//
#pragma once

#include <bits/stdc++.h>

template<typename T>
concept Printable = requires(std::ostream &os, T t) {
    { os << t } -> std::convertible_to<std::ostream &>;
};

// function declarations
template<Printable T>
void print(const T &x);

void print(const char &x);
void print(const std::string &x);
void print(const char *const &x);
void print(const bool &x);

template<typename T, typename V>
void print(const std::pair<T, V> &x);

template<typename... Args>
void print(const std::tuple<Args...> &t);

template<std::ranges::range T>
void print(const T &x);

template<typename T>
void print(const std::vector<T> &x);

template<typename T, size_t N>
void print(const std::array<T, N> &x);

template<typename T, typename U>
void print(const std::map<T, U> &x);

template<typename T, typename U>
void print(const std::unordered_map<T, U> &x);

template<typename T>
void print(const std::set<T> &x);

template<typename T>
void print(const std::unordered_set<T> &x);

template<typename T>
void print(const std::queue<T> &x);

template<typename T>
void print(const std::stack<T> &x);

template<typename T, typename Container = std::vector<T>, typename Compare = std::less<T>>
void print(const std::priority_queue<T, Container, Compare> &x);

// function definitions
template<Printable T>
void print(const T &x) {
    std::cerr << x;
}

inline void print(const char &x) {
    std::cerr << '\'' << x << '\'';
}

inline void print(const std::string &x) {
    std::cerr << '\"' << x << '\"';
}

inline void print(const char *const &x) {
    std::cerr << '\"' << x << '\"';
}

inline void print(const bool &x) {
    std::cerr << (x ? "true" : "false");
}

template<typename T, typename U>
void print(const std::pair<T, U> &x) {
    std::cerr << "pair{";
    print(x.first);
    std::cerr << ", ";
    print(x.second);
    std::cerr << "}";
}

template<typename... Args>
void print(const std::tuple<Args...> &t) {
    std::cerr << "tuple{";
    std::apply([&](const Args &...args) {
        ((print(args), std::cerr << ", "), ...);
    },
               t);
    std::cerr << "}";
}

template<std::ranges::range T>
void print(const T &x) {
    std::cerr << "{";
    int i = 0;
    for (auto &val: x) {
        std::cerr << (i++ ? ", " : "");
        print(val);
    }
    std::cerr << "}";
}

template<typename T>
void print(const std::vector<T> &x) {
    std::cerr << "vector{";
    for (int i = 0; i < x.size(); ++i) {
        std::cerr << (i ? ", " : "");
        print(x[i]);
    }
    std::cerr << "}";
}

template<typename T, size_t N>
void print(const std::array<T, N> &x) {
    std::cerr << "array{";
    for (int i = 0; i < x.size(); ++i) {
        std::cerr << (i ? ", " : "");
        print(x[i]);
    }
    std::cerr << "}";
}

template<typename T, typename U>
void print(const std::map<T, U> &x) {
    std::cerr << "map{";
    int i = 0;
    for (const auto &[f, s]: x) {
        std::cerr << (i++ ? ", " : "");
        print(f);
        std::cerr << ": ";
        print(s);
    }
    std::cerr << "}";
}

template<typename T, typename U>
void print(const std::unordered_map<T, U> &x) {
    std::cerr << "u_map{";
    int i = 0;
    for (const auto &[f, s]: x) {
        std::cerr << (i++ ? ", " : "");
        print(f);
        std::cerr << ": ";
        print(s);
    }
    std::cerr << "}";
}

template<typename T>
void print(const std::set<T> &x) {
    std::cerr << "set{";
    int i = 0;
    for (const auto &val: x) {
        std::cerr << (i++ ? ", " : "");
        print(val);
    }
    std::cerr << "}";
}

template<typename T>
void print(const std::unordered_set<T> &x) {
    std::cerr << "u_set{";
    int i = 0;
    for (const auto &val: x) {
        std::cerr << (i++ ? ", " : "");
        print(val);
    }
    std::cerr << "}";
}

template<typename T>
void print(const std::queue<T> &x) {
    std::cerr << "queue{";
    auto q = x;
    while (!q.empty()) {
        print(q.front());
        q.pop();
        if (!q.empty()) {
            std::cerr << "<-";
        }
    }
    std::cerr << "}";
}

template<typename T>
void print(const std::stack<T> &x) {
    std::cerr << "stack{";
    auto s = x;
    while (!s.empty()) {
        print(s.top());
        s.pop();
        if (!s.empty()) {
            std::cerr << "<-";
        }
    }
    std::cerr << "}";
}

template<typename T, typename Container, typename Compare>
void print(const std::priority_queue<T, Container, Compare> &x) {
    std::cerr << "pq{";
    auto pq = x;
    while (!pq.empty()) {
        print(pq.top());
        pq.pop();
        if (!pq.empty()) {
            std::cerr << "<-";
        }
    }
    std::cerr << "}";
}

#define dbg(expr...) ([&, __func = __func__] {                          \
    auto &&__tmp = (expr);                                              \
    auto __val = std::forward<decltype(__tmp)>(__tmp);                  \
    std::cerr << __func << ":" << __LINE__ << ": [" << #expr << "] = "; \
    print(__val);                                                       \
    std::cerr << endl;                                                  \
    return __val;                                                       \
}())
