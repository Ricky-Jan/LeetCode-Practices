#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};

        vector<vector<int>> pacificVisited(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlanticVisited(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> result;
        stack<pair<int, int>> st;
        
        int m = heights.size();
        int n = heights[0].size();

        auto dfs = [&](vector<vector<int>>& visited) {
            while (!st.empty()) {
                auto [i, j] = st.top();
                st.pop();

                if (visited[i][j]) continue;

                visited[i][j] = 1;

                int dirI[] = {1, -1, 0, 0};
                int dirJ[] = {0, 0, 1, -1};

                for (int k = 0; k < 4; k++) {
                    int ni = i + dirI[k];
                    int nj = j + dirJ[k];

                    if (
                        ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        !visited[ni][nj] &&
                        heights[ni][nj] >= heights[i][j]
                    ) {
                        st.push({ni, nj});
                    }
                }
            }
        };

        for (int i = 0; i < m; i++) {
            st.push({i, 0});
        }

        for (int j = 0; j < n; j++) {
            st.push({0, j});
        }
        dfs(pacificVisited);

        for (int i = 0; i < m; i++) {
            st.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            st.push({m - 1, j});
        }
        dfs(atlanticVisited);

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};

void print2dVector(const vector<vector<int>>& v) {
    for (const auto& row : v) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> height = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };

    vector<vector<int>> result = sol.pacificAtlantic(height);

    print2dVector(result);

    return 0;
}