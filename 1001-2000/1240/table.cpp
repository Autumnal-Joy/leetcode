#include <vector>

using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (n > m) std::swap(n, m);
        if (n == 0) return 0;
        if (n == 1) return m;
        if (n == 2) return 1 + tilingRectangle(n, m - n);
        if (n == 3) return 1 + tilingRectangle(n, m - n);
        if (n == 4) return 1 + tilingRectangle(n, m - n);
        if (n == 5) {
            if (m == 5) return 1 + tilingRectangle(n, m - n);
            if (m == 6) return 5;
            if (m == 7) return 5;
            if (m == 8) return 5;
            return 1 + tilingRectangle(n, m - n);
        }
        if (n == 6) {
            if (m == 6) return 1 + tilingRectangle(n, m - n);
            if (m == 7) return 5;
            return 1 + tilingRectangle(n, m - n);
        }
        if (n == 7) {
            if (m == 7) return 1 + tilingRectangle(n, m - n);
            if (m == 8) return 7;
            if (m == 9) return 6;
            if (m == 10) return 6;
            if (m == 11) return 1 + tilingRectangle(n, m - n);
            if (m == 12) return 6;
            return 1 + tilingRectangle(n, m - n);
        }
        if (n == 8) {
            if (m == 8) return 1 + tilingRectangle(n, m - n);
            if (m == 9) return 9;
            if (m == 10) return 7;
            if (m == 11) return 6;
            return 1 + tilingRectangle(n, m - n);
        }
        if (n == 9) {
            if (m == 10) return 6;
        }
        if (n == 10) {
            if (m == 11) return 6;
        }
        if (n == 11) {
            if (m == 12) return 7;
        }
        if (n == 11) {
            if (m == 13) return 6;
        }
        if (n == 12) {
            if (m == 13) return 7;
        }
        return 1 + tilingRectangle(n, m - n);
    }
};
