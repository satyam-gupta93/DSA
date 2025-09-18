#include <iostream>
#include <climits>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root,int &ans){


    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info curr;

    curr.maxi = max(root->data,right.maxi);
    curr.mini = min(root->data,left.mini);
    curr.size = left.size + right.size + 1;

    if( left.isBST && right.isBST && (  left.maxi < root->data  && root->data < right.mini ) ){
        curr.isBST = true;
    }else{
        curr.isBST = false;
    }

    if(curr.isBST){
        ans  = max(ans,curr.size);
    }

    return curr;
}
int maxBST(Node* root){
    int ans = 0;

    info temp = solve(root,ans);

    return ans;
}


int main() {
    // Example Tree
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);


    int ans = maxBST(root);

    cout<<"Largest BST:"<<ans<<endl;

   
}
