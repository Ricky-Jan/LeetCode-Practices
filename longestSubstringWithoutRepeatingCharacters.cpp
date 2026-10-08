#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int n = s.size();

        while (right < n) {
            if (window.count(s[right])) {
                left = max(left, window[s[right]] + 1);
            }

            window[s[right]] = right;

            int len = (right - left + 1);
            if (len > maxLen) {
                maxLen = len; 
            }

            right++;
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    string str = "abcabcbb";

    int result = sol.lengthOfLongestSubstring(str);

    cout << result << endl;

    return 0;
}