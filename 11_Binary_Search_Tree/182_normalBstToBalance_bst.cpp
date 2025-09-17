#include <iostream>
#include <vector>
#include<queue>
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


void findInorder(Node* root, vector<int>& inorder) {
    if (root == NULL) return;
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}


Node* inorderToBST(int s, int e, vector<int>& inorder) {
    if (s > e) return NULL;

    int mid = s + (e - s) / 2;
    Node* newRoot = new Node(inorder[mid]);

    newRoot->left = inorderToBST(s, mid - 1, inorder);
    newRoot->right = inorderToBST(mid + 1, e, inorder);

    return newRoot;
}


Node* balanceBST(Node* root) {
    vector<int> inorder;
    findInorder(root, inorder);
    return inorderToBST(0, inorder.size() - 1, inorder);
}

// Print levelorder
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


int main() {
    // Manually constructing an unbalanced BST
    //       10
    //      /
    //     8
    //    /
    //   7
    //  /
    // 6
    // /
    // 5
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);

    cout << "Original BST:"<<endl;
     printLevelOrder(root);
    cout << endl;

    Node* balanced = balanceBST(root);

    cout << "Balanced BST:"<<endl;
     printLevelOrder(balanced);
    cout << endl;

    return 0;
}
