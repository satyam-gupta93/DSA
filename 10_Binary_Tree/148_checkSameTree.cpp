#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p == nullptr || q == nullptr) return false;
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* temp1 = q1.front();
            q1.pop();
            TreeNode* temp2 = q2.front();
            q2.pop();

            if(temp1->val!=temp2->val){
                return false;
            }

            if(temp1->left){
                if(temp2->left==NULL){
                    return false;
                }else{
                    q1.push(temp1->left);
                }
            }
            if(temp1->right){
                if(temp2->right==NULL){
                    return false;
                }else{
                    q1.push(temp1->right);
                }
            }
            if(temp2->left){
                if(temp1->left==NULL){
                    return false;
                }else{
                    q2.push(temp2->left);
                }
            }
            if(temp2->right){
                if(temp1->right==NULL){
                    return false;
                }else{
                    q2.push(temp2->right);
                }
            }
        }
        return q1.empty() && q2.empty();
    }

    bool sameTreeRecursive(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }


        if(p->val!=q->val){
            return false;
        }

        return sameTreeRecursive(p->left,q->left) && sameTreeRecursive(p->right,q->right);
    }
};

int main() {
    // Example 1: p = [1,2,3], q = [1,2,3]
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "true" : "false") << endl;
     cout <<"Recursive:"<< (sol.sameTreeRecursive(p, q) ? "true" : "false") << endl;

    // Example 2: p = [1,2], q = [1,null,2]
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;
    cout << (sol.sameTreeRecursive(p2, q2) ? "true" : "false") << endl;

    return 0;
}
