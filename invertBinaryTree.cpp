#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *curr = s.top();
            s.pop();

            swap(curr->left, curr->right);
            
            if (curr->left != nullptr) {
                s.push(curr->left);
            }

            if (curr->right != nullptr) {
                s.push(curr->right);
            }
        }

        return root;
    }
};

TreeNode *buildTree(vector<int> nums) {
    if (nums.empty()) return nullptr;

    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    size_t i = 1;

    q.push(root);

    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nums.size()) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
            i++;
        }

        if (i < nums.size()) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
            i++;
        }
    }

    return root;
}

void printTree(TreeNode *root) {
    if (root == nullptr) return;

    stack<pair<TreeNode *, int>> s;
    TreeNode* curr = root;
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
    vector<int> nums = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = buildTree(nums);

    cout << "Before:" << endl;
    printTree(root);

    sol.invertTree(root);

    cout << "After:" << endl;
    printTree(root);

    return 0;
}