#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    erase(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    void erase(vector<vector<char>>& grid, size_t i, size_t j) {
        size_t currI, currJ;

        stack<pair<size_t, size_t>> st;
        st.push({i, j});
        while (!st.empty()) {
            auto elem = st.top();
            st.pop();
            currI = elem.first;
            currJ = elem.second;
            grid[currI][currJ] = '0';

            if (currI < grid.size() - 1 && grid[currI + 1][currJ] == '1') st.push({currI + 1, currJ});
            if (currI > 0 && grid[currI - 1][currJ] == '1') st.push({currI - 1, currJ});
            if (currJ < grid[currI].size() - 1 && grid[currI][currJ + 1] == '1') st.push({currI, currJ + 1});
            if (currJ > 0 && grid[currI][currJ - 1] == '1') st.push({currI, currJ - 1});
        }
    }
};


int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '1'},
    };

    int result = sol.numIslands(grid);

    cout << result << endl;

    return 0;
}