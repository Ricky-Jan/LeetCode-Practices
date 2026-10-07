#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int bestArea = 0;

        while (right > left) {
            int currArea = min(height[right], height[left]) * (right - left);

            if (currArea > bestArea) {
                bestArea = currArea;
            }

            if (height[right] > height[left]) {
                left++;
            } else {
                right--;
            }
        }

        return bestArea;
    }
};

int main() {
    Solution sol;
    vector<int> height = {4, 3, 2, 1, 4};

    int result = sol.maxArea(height);

    cout << result << endl;

    return 0;
}