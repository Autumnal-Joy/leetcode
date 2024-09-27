#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // RLRRL
  // 02234
  // 11333
  // R左侧的X数量增加，L左侧的X数量减少
  bool canTransform(string start, string end) {
    if (start.size() != end.size()) {
      return false;
    }
    string start_RL, end_RL;
    vector<int> start_X, end_X;
    int X_cnt = 0;
    for (auto s : start) {
      if (s == 'X') {
        X_cnt++;
      } else {
        start_RL.push_back(s);
        start_X.push_back(X_cnt);
      }
    }
    X_cnt = 0;
    for (auto s : end) {
      if (s == 'X') {
        X_cnt++;
      } else {
        end_RL.push_back(s);
        end_X.push_back(X_cnt);
      }
    }
    if (start_RL != end_RL) {
      return false;
    }
    for (int i = 0; i < start_X.size(); i++) {
      if (start_RL[i] == 'R' && start_X[i] > end_X[i]) {
        return false;
      } else if (start_RL[i] == 'L' && start_X[i] < end_X[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  auto s = Solution();
  cout << s.canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
  return 0;
}
