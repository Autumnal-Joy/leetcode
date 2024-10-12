#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int bitmap;

    Solution() : bitmap(0) {}

    static int str2int(const string &s) {
        int res = 0;
        for (char c: s) {
            res |= 1 << (c - 'a');
        }
        return res;
    }

    int dfs(vector<string> &arr, int begin, int size) {
        if (begin == arr.size()) {
            return size;
        }


        int include = dfs(arr, begin + 1, size);
        int bitmapBegin = str2int(arr[begin]);

        if (bitmap & bitmapBegin) {
            return include;
        }

        bitmap |= bitmapBegin;
        int exclude = dfs(arr, begin + 1, size + static_cast<int>(arr[begin].size()));
        bitmap &= ~bitmapBegin;

        return std::max({include, exclude});
    }

    int maxLength(vector<string> &arr) {
        auto temp = vector<string>();
        std::copy_if(arr.begin(), arr.end(), std::back_inserter(temp), [](const string &s) {
            int m = 0;
            for (char c: s) {
                if (m & 1 << (c - 'a')) {
                    return false;
                }
                m |= 1 << (c - 'a');
            }
            return true;
        });

        if (temp.empty()) {
            return 0;
        }
        return dfs(temp, 0, 0);
    }
};

int main() { return 0; }
