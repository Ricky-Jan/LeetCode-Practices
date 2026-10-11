#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '[' && c == ']') ||
                    (st.top() == '{' && c == '}')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string str = "([]){}";

    bool result = sol.isValid(str);

    cout << boolalpha << result << endl;

    return 0;
}