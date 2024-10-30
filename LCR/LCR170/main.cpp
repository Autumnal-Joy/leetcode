#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static int merge(vector<int> &record, const int start, const int mid, const int end, const vector<int> &temp) {
        int i = start, j = mid, k = start;
        int cnt = 0;
        while (i < mid && j < end) {
            if (temp[i] <= temp[j]) {
                record[k++] = temp[i++];
            } else {
                cnt += mid - i;
                record[k++] = temp[j++];
            }
        }
        while (i < mid) {
            record[k++] = temp[i++];
        }
        while (j < end) {
            record[k++] = temp[j++];
        }
        return cnt;
    }
    int mergeSort(vector<int> &record, const int start, const int end, vector<int> &temp) {
        if (end - start <= 1) {
            return 0;
        }
        const int mid = (start + end) / 2;
        int res = 0;
        res += mergeSort(temp, start, mid, record);
        res += mergeSort(temp, mid, end, record);
        res += merge(record, start, mid, end, temp);
        return res;
    }

public:
    int reversePairs(vector<int> &record) {
        if (record.empty()) {
            return 0;
        }
        auto temp = record;
        return mergeSort(record, 0, static_cast<int>(record.size()), temp);
    }
};

#ifdef LEETCODE
int main() {
    auto record = vector({7, 5, 6, 4});
    cout << Solution().reversePairs(record) << endl;
    return 0;
}
#endif
