#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return -1;

        int ans = nums[0];
        int currMax = ans;
        int currMin = ans;

        for (size_t i = 1; i < nums.size(); i++) {
            int n = nums[i];

            if (n < 0) {
                swap(currMax, currMin);
            }

            currMax = max(n, currMax * n);
            currMin = min(n, currMin * n);
            ans = max(ans, currMax);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};

    int result = sol.maxProduct(nums);

    cout << result << endl;

    return 0;
}