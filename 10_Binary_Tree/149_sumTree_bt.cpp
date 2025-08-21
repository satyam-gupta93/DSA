#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check children-sum property
int check(TreeNode* root, int &c) {
    if (root == NULL) return 0;

    // leaf node -> return value
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }

    int ls = check(root->left, c);
    int rs = check(root->right, c);

    // if current node doesn't satisfy property
    if (root->val != ls + rs) {
        c = 0;
    }

    return root->val;
}

class Solution {
public:
    bool checkTree(TreeNode* root) {
        int c = 1;
        check(root, c);
        return c == 1;
    }
};

// ------------------- SIMPLE MAIN -------------------
int main() {
    /*
        Constructing this tree:

              10
             /  \
            8    2
           / \    \
          3   5    2

        This tree satisfies children-sum property
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(2);

    Solution sol;
    if (sol.checkTree(root)) {
        cout << "Tree satisfies children-sum property\n";
    } else {
        cout << "Tree does NOT satisfy children-sum property\n";
    }
    cout<<"Hello!";
    return 0;
}
