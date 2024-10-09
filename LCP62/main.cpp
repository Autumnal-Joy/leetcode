#include <unordered_set>
#include <vector>

using namespace std;

//class Solution {
//    class HashPair {
//        hash<int> hash;
//    public:
//        size_t operator()(const pair<int, int> &p) const {
//            size_t seed = 0;
//            seed ^= hash(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//            seed ^= hash(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//            return seed;
//        }
//    };
//
//public:
//    int transportationHub(vector<vector<int>> &path) {
//        auto s = unordered_set<pair<int, int>, HashPair>();
//        for (const auto &p: path) {
//            s.insert({p[0], p[1]});
//        }
//        auto cntIn = vector<int>(1001);
//        auto cntOut = vector<int>(1001);
//        auto nodes = unordered_set<int>();
//        for (const auto &p: s) {
//            ++cntOut[p.first];
//            ++cntIn[p.second];
//            nodes.insert(p.first);
//            nodes.insert(p.second);
//        }
//        for (const auto &n: nodes) {
//            if (cntIn[n] == nodes.size() - 1 && cntOut[n] == 0) {
//                return n;
//            }
//        }
//        return -1;
//    }
//};

class Solution {
public:
    int transportationHub(vector<vector<int>> &path) {
        auto cntIn = vector<int>(1001);
        auto cntOut = vector<int>(1001);
        auto nodes = unordered_set<int>();
        for (const auto &p: path) {
            ++cntOut[p[0]];
            ++cntIn[p[1]];
            nodes.insert(p[0]);
            nodes.insert(p[1]);
        }
        for (const auto &n: nodes) {
            if (cntIn[n] == nodes.size() - 1 && cntOut[n] == 0) {
                return n;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    return 0;
}
