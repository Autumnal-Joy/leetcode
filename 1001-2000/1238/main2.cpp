#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<bool> visited;
    bool dfs(int n, int start) {
        if (path.size() == (1 << n)) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            auto next = start ^ (1 << i);
            if (visited[next]) { continue; }
            visited[next] = true;
            path.push_back(next);
            if (dfs(n, next)) { return true; }
            path.pop_back();
            visited[next] = false;
        }
        return false;
    }
    vector<int> circularPermutation(int n, int start) {
        path.push_back(start);
        visited.resize(1 << n);
        visited[start] = true;
        dfs(n, start);
        return path;
    }
};

int main() {
    return 0;
}
