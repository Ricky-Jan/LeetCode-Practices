#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> results;

        for (int i = 0; i < n; i++) {
            int currVal = nums[i];

            if ((i > 0) && (currVal == nums[i - 1])) continue;

            int left = i + 1;
            int right = n - 1;

            while (right > left) {
                int rightVal = nums[right];
                int leftVal = nums[left];
                int sum = currVal + leftVal + rightVal;

                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    results.push_back({currVal, leftVal, rightVal});
                    right--;
                    left++;

                    while (nums[right] == nums[right + 1] && right > left) {
                        right--;
                    }

                    while (nums[left] == nums[left - 1] && right > left) {
                        left++;
                    }
                }
            }
        }

        return results;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 0, 0, 2, 2};

    vector<vector<int>> results = sol.threeSum(nums);

    for (int i = 0; i < results.size(); i++) {
        vector<int> curr = results[i];
        int n = curr.size();

        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << curr[j];
            if (j < n - 1) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }

    return 0;
}