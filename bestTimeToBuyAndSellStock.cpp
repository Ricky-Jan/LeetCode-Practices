#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int lowest = prices[0];
        int maxProfit = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            } else {
                int currProfit = prices[i] - lowest;
                maxProfit = max(maxProfit, currProfit);
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = sol.maxProfit(prices);

    cout << result << endl;

    return 0;
}