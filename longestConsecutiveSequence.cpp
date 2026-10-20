#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxLength = 0;
        for (const auto& n : s) {
            if (!s.count(n - 1)) {
                int length = 1;
                int curr = n;

                while (s.count(curr + 1)) {
                    length++;
                    curr++;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = sol.longestConsecutive(nums);

    cout << result << endl;

    return 0;
}