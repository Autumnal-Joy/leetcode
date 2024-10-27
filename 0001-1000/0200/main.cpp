#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class UnionFind {
private:
    std::vector<int> parent;// 存储每个元素的父节点
    std::vector<int> rank;  // 存储每棵树的秩（可以理解为树的高度）

public:
    int cnt;// 并查集中集合的数量
    // 构造函数，初始化并查集
    UnionFind(vector<vector<char>> &grid) : cnt(0) {
        int rows = grid.size();
        int cols = grid[0].size();
        parent.resize(rows * cols);
        rank.resize(rows * cols, 1);
        // 初始时，每个节点的父节点是它自己
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    parent[i * cols + j] = i * cols + j;
                    ++cnt;
                }
            }
        }
    }

    // 查找操作，寻找某个节点的根，并进行路径压缩
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);// 路径压缩
        }
        return parent[x];
    }

    // 合并操作，将两个集合合并
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // 按秩合并，将秩较小的树挂在秩较大的树下
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX] += 1;
            }
            --cnt;
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        auto uf = UnionFind(grid);
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    if (i > 0 && grid[i - 1][j] == '1') {
                        uf.unionSets(i * cols + j, (i - 1) * cols + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        uf.unionSets(i * cols + j, i * cols + j - 1);
                    }
                }
            }
        }
        return uf.cnt;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << s.numIslands(grid) << endl;
}
