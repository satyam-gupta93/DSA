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

    void traverseLeft(Node* root, vector<int> &ans){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left,ans);
        }else{
            traverseLeft(root->right,ans);
        }
        
    }
    
    void traverseLeaf(Node *root,vector<int> &ans){
        
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        

    }
    
    void traverseRight(Node *root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right){
            traverseRight(root->right,ans);
        }else{
            traverseRight(root->left,ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
         vector<int> ans;
         if(root==NULL){
             return ans;
         }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ans;
        }
         
         ans.push_back(root->data);
         
         traverseLeft(root->left,ans);
         traverseLeaf(root,ans);
         traverseRight(root->right,ans);
         
         
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

    
   vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal:"<<endl;
   
        for(int val : result){
            cout << val << " ";
        }
    
    

    return 0;
}