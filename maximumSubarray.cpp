#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;

        int currSum = nums[0];
        int maxSum = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1};

    int result = sol.maxSubArray(nums);

    cout << result << endl;

    return 0;
}