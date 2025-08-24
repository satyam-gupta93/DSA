#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

    void solve(Node* root, vector<vector<int>> &ans, vector<int> &curr){
        if(root==NULL){
            return;
        }
        curr.push_back(root->data);
        if(root->left ==NULL && root->right ==NULL){
            ans.push_back(curr);
        }else{
            solve(root->left,ans,curr);
            solve(root->right,ans,curr);
        }

        curr.pop_back();
    }

    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root,ans,curr);
        
        
        return ans;
    }


int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 

    vector<vector<int>> res = paths(root);

    cout<<"All Paths:"<<endl;
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

    return 0;
} 