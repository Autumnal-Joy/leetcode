#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    auto find(const int key) {
        return ranges::find_if(cache, [key](const auto &pair) {
            return pair.first == key;
        });
    }

public:
    explicit LRUCache(const int capacity) : capacity(capacity) {}

    int get(const int key) {
        if (const auto it = find(key); it != cache.end()) {
            auto val = *it;
            cache.erase(it);
            cache.push_front(std::move(val));
            return cache.front().second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (const auto it = find(key); it != cache.end()) {
            cache.erase(it);
        } else if (cache.size() >= capacity) {
            cache.pop_back();
        }
        cache.emplace_front(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    return 0;
}
