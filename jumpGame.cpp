#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;

        if (nums[0] >= nums.size() - 1 || nums.size() == 1) return true;
        
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1};

    bool result = sol.canJump(nums);

    cout << boolalpha << result << endl;

    return 0;
}