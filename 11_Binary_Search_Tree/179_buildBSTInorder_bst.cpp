#include <iostream>
#include <climits>
#include<queue>
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
void printLevelOrder(Node * root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int s = q.size();

        for(int i = 0; i<s; i++){
            Node* temp = q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right) ;
            }
        }
        cout<<endl;
    }

    
}

Node* solve( vector<int> preorder,int &indx, int maxV){
    if( indx >= preorder.size() || preorder[indx] > maxV ){
        return NULL;
    }

    int ele = preorder[indx++];
    Node* root = new Node(ele);

    root->left = solve(preorder,indx,root->data);
    root->right = solve(preorder,indx,maxV);

    return root;
}


int main() {
    
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int indx = 0;

    Node* root = solve(preorder,indx,INT_MAX);

    printLevelOrder(root);


    return 0;
}
