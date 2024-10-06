#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  enum class ticketState { notUsed, used };

  bool
  solve(unordered_map<string, vector<pair<ticketState, string>>> &ticketsMap,
        const int &cnt, vector<string> &path, vector<string> &res) {
    // 是否用完票
    if (path.size() == cnt + 1) {
      res = path;
      return true;
    }

    // 是否到死路
    auto &tickets = ticketsMap[path.back()];
    if (tickets.empty()) {
      return false;
    }

    string prev;
    for (auto &ticket : tickets) {
      if (ticket.second == prev) {
        continue;
      }
      if (ticket.first == ticketState::notUsed) {
        ticket.first = ticketState::used;
        prev = ticket.second;
        path.push_back(ticket.second);
        if (solve(ticketsMap, cnt, path, res)) {
          return true;
        }
        path.pop_back();
        ticket.first = ticketState::notUsed;
      }
    }

    return false;
  }

  vector<string> findItinerary(const vector<vector<string>> &tickets) {
    auto ticketsMap =
        unordered_map<string, vector<pair<ticketState, string>>>();
    int cnt = 0;
    for (const auto &t : tickets) {
      ticketsMap[t[0]].emplace_back(ticketState::notUsed, t[1]);
      ++cnt;
    }
    for (auto &p : ticketsMap) {
      sort(p.second.begin(), p.second.end());
    }

    auto path = vector<string>({"JFK"});
    auto res = vector<string>();
    solve(ticketsMap, cnt, path, res);
    return res;
  }
};

int main() {
  auto s = Solution();
  s.findItinerary({{"JFK", "SFO"},
                   {"JFK", "ATL"},
                   {"SFO", "ATL"},
                   {"ATL", "JFK"},
                   {"ATL", "SFO"}});
  return 0;
}
