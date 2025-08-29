#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


        void levelOrderTraversal1(Node *root){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            cout<<endl;
        }

    } 


    void mapNode( map<int,int> &nodeIndex,vector<int>& inorder,int n){

        for(int i = 0; i<n; i++){
            nodeIndex[inorder[i]] = i;
        }
    }
    Node* solve(vector<int>& preorder, vector<int>& inorder,int &preIndx,int inStart,int inEnd,int n,map<int,int> &nodeIndex){

        if(preIndx>=n || inStart>inEnd){
            return NULL;
        }
        int ele = preorder[preIndx++];
        Node* root = new Node(ele);

        int inPosi = nodeIndex[ele];

        root->left = solve(preorder,inorder,preIndx,inStart,inPosi-1,n,nodeIndex);
        root->right = solve(preorder,inorder,preIndx,inPosi+1,inEnd,n,nodeIndex);

        return root;
    }
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndx = 0;
        int inStart = 0;
        int n = preorder.size();
        int inEnd = n -1;


        map<int,int> nodeIndex;

        mapNode(nodeIndex,inorder,n);

        return solve(preorder,inorder,preIndx,inStart,inEnd,n,nodeIndex);
    }

int main(){

    vector<int> inOrder = {1, 6, 8, 7};
    vector<int> postOrder = {1, 6, 7, 8};

    Node* root =  buildTree(inOrder,postOrder);

    levelOrderTraversal1(root);

}



