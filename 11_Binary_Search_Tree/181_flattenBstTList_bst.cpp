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

Node* flattenTree(Node*root,Node* &prev){

    if(root==NULL){
        return root;
    }

    Node* head = flattenTree(root->left,prev);

    if(prev){
        prev->right = root;
        prev->left = NULL;

    }else{
        head = root;
    }

    root->left = NULL;
    prev = root;

    flattenTree(root->right,prev);

    return head;

}

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    cout<<"NULL";
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

    Node* prev = NULL;
    Node* head = flattenTree(root,prev);

    print(head);
  
    return 0;


    // Time Complexity:O(n)
    // Space Complexity:O(n)


}
