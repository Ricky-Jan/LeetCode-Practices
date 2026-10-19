#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});

        TreeNode *curr;
        int depth;
        int maxDepth = 0;

        while (!s.empty()) {
            auto elem = s.top();
            s.pop();

            curr = elem.first;
            depth = elem.second;

            maxDepth = max(maxDepth, depth);

            if (curr->left != nullptr) {
                s.push({curr->left, depth + 1});
            }

            if (curr->right != nullptr) {
                s.push({curr->right, depth + 1});
            }
        }

        return maxDepth;
    }
};

void printTree(TreeNode *root) {
    if (root == nullptr) return;

    stack<pair<TreeNode *, int>> s;
    TreeNode *curr = root;
    int space = 0;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push({curr, space});
            curr = curr->right;
            space += 5;
        }

        auto elem = s.top();
        s.pop();

        curr = elem.first;
        space = elem.second;

        cout << string(space, ' ') << curr->val << endl;

        curr = curr->left;
        space += 5;
    }
}

int main() {
    Solution sol;
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;

    n2->left = nullptr;
    n2->right = nullptr;

    n3->left = n4;
    n3->right = n5;

    n4->left = nullptr;
    n4->right = nullptr;

    n5->left = nullptr;
    n5->right = nullptr;

    TreeNode *root = n1;

    // printTree(root);

    int result = sol.maxDepth(root);
    cout << result << endl;
    
    return 0;
}