#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// 当 n > 2 时，如果以叶子结点为根，则存在一条最长的到另一个叶子的路径为树的高度，大于以叶子结点相邻的结点为根的树的高度，因此叶子结点不能为根
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if(n==1){
            return {0};
        }
        if(n==2){
            return {0,1};
        }

        auto adj = vector<unordered_set<int>>(n);
        for (auto &edge: edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        auto q = queue<int>();

        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int neighbor: adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        auto res = vector<int>();

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
