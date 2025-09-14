#include <iostream>
#include <climits>
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

Node* LCA(Node* root,int p,int q){
    if(root==NULL){
        return root;
    }
    while(root!=NULL){
         if(root->data > p && root->data > q){
        root = root->left;
        }else if(root->data<p && root->data < q){
            root = root->right;
        }else{
            return root;
        }
    }

    return NULL;

}

int main() {
    // Example Tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    Node* ans = LCA(root,2,4);
    cout<<"LCA:"<<ans->data;

    return 0;
}
