#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            }
        );

        int keep = 0;
        int prevEnd = INT_MIN;
        
        for (const auto& curr : intervals) {
            if (curr[0] >= prevEnd) {
                keep++;
                prevEnd = curr[1];
            }
        }

        return intervals.size() - keep;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int result = sol.eraseOverlapIntervals(intervals);

    cout << result << endl;

    return 0;
}