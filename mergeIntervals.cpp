#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++) {
            vector<int> currRow = intervals[i];
            const auto& prevRow = ans.back();
            if (prevRow[1] >= currRow[0]) {
                ans.back()[1] = max(prevRow[1], currRow[1]);
            } else {
                ans.push_back(currRow);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{2, 6}, {15, 18}, {8, 10}, {1, 3}};

    vector<vector<int>> result = sol.merge(intervals);

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        vector<int> row = result[i];
        for (size_t j = 0; j < row.size(); j++) {
            cout << row[j];
            if (j < row.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}