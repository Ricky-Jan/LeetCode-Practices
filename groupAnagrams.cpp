#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        vector<string> curr = result[i];
        for (int j = 0; j < curr.size(); j++) {
            cout << curr[j];
            if (j < curr.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
                cout << ", ";
            }
    }
    cout << "]" << endl;
    return 0;
}