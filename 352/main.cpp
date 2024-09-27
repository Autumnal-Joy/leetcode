#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class SummaryRanges {
 private:
  list<vector<int>> intervals;

 public:
  SummaryRanges() {}

  // [2, 2] [5, 5] [7, 7]
  void addNum(int value) {
    auto it = intervals.begin();
    while (it != intervals.end() && (*it)[1] + 1 < value) {
      ++it;
    }
    if (it == intervals.end()) {
      intervals.push_back({value, value});
    } else if (value < (*it)[0] - 1) {
      // it左侧不相邻
      intervals.insert(it, {value, value});
    } else if (value == (*it)[0] - 1) {
      // it左侧相邻
      (*it)[0] = value;
    } else if (value <= (*it)[1]) {
      // it区间内
    } else {
      // it右侧相邻
      (*it)[1] = value;
      if (next(it) != intervals.end() && value == (*next(it))[0] - 1) {
        (*it)[1] = (*next(it))[1];
        intervals.erase(next(it));
      }
    }
  }

  vector<vector<int>> getIntervals() {
    return vector<vector<int>>(intervals.begin(), intervals.end());
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void print(const vector<vector<int>>& intervals) {
  for_each(intervals.begin(), intervals.end(), [](const vector<int>& row) {
    cout << "[";
    copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
    cout << "\b] ";
  });

  cout << endl;
}

int main() {
  SummaryRanges* obj = new SummaryRanges();
  obj->addNum(1);
  print(obj->getIntervals());
  obj->addNum(3);
  print(obj->getIntervals());
  obj->addNum(7);
  print(obj->getIntervals());
  obj->addNum(2);
  print(obj->getIntervals());
  obj->addNum(6);
  print(obj->getIntervals());
  return 0;
}
