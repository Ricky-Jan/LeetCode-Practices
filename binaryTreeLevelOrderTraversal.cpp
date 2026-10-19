#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int children = q.size();
            vector<int> v;
            for (int i = 0; i < children; i++) {
                TreeNode *curr = q.front();
                q.pop();

                v.push_back(curr->val);

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            result.push_back(v);
        }

        return result;
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

void print2dVector(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j < v[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
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

    vector<vector<int>> result = sol.levelOrder(root);

    print2dVector(result);

    return 0;
}