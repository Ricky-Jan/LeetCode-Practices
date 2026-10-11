#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    return false;
                }

                if ((stack.back() == '(' && c == ')') ||
                    (stack.back() == '[' && c == ']') ||
                    (stack.back() == '{' && c == '}')) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution sol;
    string str = "([]){})";

    bool result = sol.isValid(str);

    cout << boolalpha << result << endl;

    return 0;
}