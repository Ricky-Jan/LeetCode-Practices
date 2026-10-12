#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i >= c) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);

    cout << result << endl;

    return 0;
}