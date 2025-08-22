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

    
    vector<int> verticalOrderTraversal(Node *root) {
       
         vector<int> ans;

         if(root==NULL){
            return ans;
         }
        // map<indx,level<values>
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();

            Node* curr = temp.first;
            int indx = temp.second.first;
            int lvl = temp.second.second;

            nodes[indx][lvl].push_back(curr->data);

            if(curr->left){
                q.push({curr->left,{indx-1,lvl+1}});
            }
            if(curr->right){
                q.push({curr->right,{indx+1,lvl+1}});
            }


        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
         
         
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

    
   vector<int> result = verticalOrderTraversal(root);

    cout << "Vertical Order Traversal:"<<endl;
   
        for(int val : result){
            cout << val << " ";
        }
        cout<<"Hello";
    
    

    return 0;
}