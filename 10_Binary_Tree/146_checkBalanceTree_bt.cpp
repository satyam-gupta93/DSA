#include <iostream>
#include <cmath>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Helper function */
int check(TreeNode* root, int &c) {
    if (root == NULL) {
        return 0;
    }

    int lh = check(root->left, c);
    int rh = check(root->right, c);

    if (abs(lh - rh) > 1) {
        c = 1; // mark unbalanced
        return 0;
    }

    return max(lh, rh) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int c = 0;
        check(root, c);
        return (c == 0);
    }
};

int main() {
    // Build this tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "Tree is balanced" << endl;
    } else {
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}
