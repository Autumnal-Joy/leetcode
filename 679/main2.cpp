#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  bool DIGIT = true;
  bool OPERATOR = false;
  vector<int> operators = {'+', '-', '*', '/'};

public:
  double calculate(deque<pair<bool, int>> s) {
    auto t = stack<double>();
    while (!s.empty()) {
      auto p = s.front();
      s.pop_front();
      if (p.first == DIGIT) {
        t.push(p.second);
      } else {
        double b = t.top();
        t.pop();
        double a = t.top();
        t.pop();
        if (p.second == '+') {
          t.push(a + b);
        } else if (p.second == '-') {
          t.push(a - b);
        } else if (p.second == '*') {
          t.push(a * b);
        } else if (p.second == '/') {
          if (b == 0) {
            return 0;
          }
          t.push(a / b);
        }
      }
    }
    return t.top();
  }

  bool dfs(const vector<int> &cards, deque<pair<bool, int>> &s,
           vector<bool> &visited, int cntNum, int cntOperator) {
    if (cntNum == 4 && cntOperator == 3) {
      return abs(calculate(s) - 24) < 1e-6;
    }
    for (int i = 0; i < cards.size(); ++i) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      s.emplace_back(DIGIT, cards[i]);
      if (dfs(cards, s, visited, cntNum + 1, cntOperator)) {
        return true;
      }
      s.pop_back();
      visited[i] = false;
    }

    if (cntOperator + 1 < cntNum) {
      for (int &i : operators) {
        s.emplace_back(OPERATOR, i);
        if (dfs(cards, s, visited, cntNum, cntOperator + 1)) {
          return true;
        }
        s.pop_back();
      }
    }
    return false;
  }

  bool judgePoint24(vector<int> &cards) {
    auto s = deque<pair<bool, int>>();
    auto visited = vector<bool>(4);
    return dfs(cards, s, visited, 0, 0);
  }
};

int main() {
  auto s = Solution();
  return 0;
}
