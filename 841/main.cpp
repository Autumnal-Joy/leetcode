#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = static_cast<int>(rooms.size());
    auto visited = vector<bool>(n);
    auto q = queue<int>({0});
    while (!q.empty()) {
      int key = q.front();
      q.pop();
      if (!visited[key]) {
        visited[key] = true;
        for (const auto &k : rooms[key]) {
          q.push(k);
        }
      }
    }
    return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
  }
};

int main() {
  auto s = Solution();
  return 0;
}
