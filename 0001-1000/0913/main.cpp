#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// f(1,2)
// = merge{f(3,3)=2 f(3,6)=1 f(5,3)=? f(5,6)=?}
// f(5,3) = 1
// = merge{f(1,1)=2 f(1,2)=? f(4,1)=1 f(4,2)=1}
// f(5,6)
// = merge{f(1,2)=? f(1,4)=? f(4,2)=1 f(4,4)=2}
// f(1,4) = 1
// = merge{f(3,5)=1 f(3,6)=1 f(5,5)=2 f(5,6)=?}

// - - - - - - -
// - 2 ? ? ? ? ?
// - ? 2 ? ? ? ?
// - 1 1 2 1 1 1
// - 1 1 1 2 1 1
// - ? ? ? ? 2 ?
// - ? ? ? ? ? 2

class Solution {
public:
    static void printMatrix(const vector<vector<int>> &matrix) {
        for (const auto &row: matrix) {
            for (int value: row) {
                cout << setw(4) << value;// 设置宽度
            }
            cout << endl;
        }
        cout << endl;
    }

    static bool update(vector<vector<int>> &results,
                       const vector<vector<int>> &graph) {
        bool isUpdate = false;
        for (int i = 1; i < graph.size(); i++) {
            for (int j = 1; j < graph.size(); j++) {
                if (results[i][j] != 0) {
                    continue;
                }
                bool isCatAllWin = true;
                for (auto adj1: graph[i]) {
                    bool isMouseAllWin = true;
                    bool isCatMayWin = false;
                    if (adj1 == j) {
                        isMouseAllWin = false;
                        isCatMayWin = true;
                    } else {
                        for (auto adj2: graph[j]) {
                            if (adj2 == 0)
                                continue;
                            isMouseAllWin = isMouseAllWin && (results[adj1][adj2] == 1);
                            isCatMayWin = isCatMayWin || (results[adj1][adj2] == 2);
                        }
                    }
                    isCatAllWin = isCatAllWin && isCatMayWin;
                    if (isMouseAllWin) {
                        results[i][j] = 1;
                        isUpdate = true;
                    }
                }
                if (isCatAllWin) {
                    results[i][j] = 2;
                    isUpdate = true;
                }
            }
        }
        return isUpdate;
    }

    static int catMouseGame(vector<vector<int>> &graph) {
        vector<vector<int>> results(graph.size(), vector<int>(graph.size()));
        for (auto adj: graph[0]) {
            for (int i = 1; i < graph.size(); i++) {
                results[adj][i] = 1;
            }
        }
        for (int i = 1; i < graph.size(); i++) {
            results[i][i] = 2;
        }
        while (update(results, graph)) {
            printMatrix(results);
        }

        return results[1][2];
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> graph = {{2, 5},
                                 {3},
                                 {0, 4, 5},
                                 {1, 4, 5},
                                 {2, 3},
                                 {0, 2, 3}};
    cout << Solution::catMouseGame(graph) << endl;
    return 0;
}
