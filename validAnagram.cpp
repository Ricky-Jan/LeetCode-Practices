#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int length = s.length();

        if (length != t.length()) return false;

        vector<int> count(26, 0);
        for (int i = 0; i < length; i++) {
            int offset_s = s[i] - 'a';
            int offset_t = t[i] - 'a';

            count[offset_s] += 1;
            count[offset_t] -= 1;
        }

        return count == vector<int> (26, 0);
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    bool result = sol.isAnagram(s, t);

    cout << (result ? "Yes" : "No") << endl;
    
    return 0;
}