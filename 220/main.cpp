#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Window {
private:
  list<int> data;

public:
  int minDiff;

  Window(vector<int>&& nums) : minDiff(INT_MAX) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      minDiff = min({minDiff, abs(nums[i - 1] - nums[i])});
    }
    copy(nums.begin(), nums.end(), back_inserter(data));
  }

  void replace(int replaced, int replacing) {
    if (replaced == replacing) {
      return;
    }
    auto it = find(data.begin(), data.end(), replaced);
    data.erase(it);
    it = data.begin();
    if (data.empty()) {
      // 列表为空
      data.push_back(replacing);
    } else if (replacing <= *it) {
      minDiff = min({minDiff, abs(*it - replacing)});
      data.push_front(replacing);
    } else if (replacing >= data.back()) {
      minDiff = min({minDiff, abs(data.back() - replacing)});
      data.push_back(replacing);
    } else {
      while (it != data.end() && next(it) != data.end() &&
             *next(it) < replacing) {
        ++it;
      }
      minDiff =
          min({minDiff, abs(*it - replacing), abs(*next(it) - replacing)});
      data.insert(next(it), replacing);
    }
  }
};

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    int windowSize = min({indexDiff + 1, (int)nums.size()});
    auto w = Window(std::move(vector<int>(nums.begin(), nums.begin() + windowSize)));
    if (w.minDiff <= valueDiff) {
      return true;
    }
    for (int i = windowSize; i < nums.size(); i++) {
      w.replace(nums[i - windowSize], nums[i]);
      if (w.minDiff <= valueDiff) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 3, 1};
  cout << s.containsNearbyAlmostDuplicate(nums, 1, 1) << endl;
  return 0;
}
