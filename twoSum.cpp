#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int curr_val = nums[i];
            int target_val = target - curr_val;

            if (map.count(target_val)) {
                return {map[target_val], i};
            } else {
                map[curr_val] = i;
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}