#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<int> ans;
        int prodL = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            ans.push_back(prodL);
            prodL *= nums[i];
        }

        int prodR = 1;
        for (size_t i = nums.size(); i > 0; i--) {
            ans[i - 1] *= prodR;
            prodR *= nums[i - 1];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}