#include<iostream>
#include<queue>
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

Node* searchBSTRecursive(Node* root,int val){

    if(root==NULL){
        return root;
    }

    if(root->data == val){
        return root;
    }
    if(root->data < val){
        return searchBSTRecursive(root->right,val);
    } else if(root->data > val){
        return searchBSTRecursive(root->left,val);
    }
}

Node* searchBSTIterative(Node* root,int val){

    if(root==NULL){
        return root;
    }

    while(root!=NULL && root->data!=val){
        if(root->data < val ){
             root = root->right ;
        }else if(root->data > val ){
            root = root->left ;
        }
    }

    return root;
}

int main(){


    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout<<"Recursive solution"<<endl;
    // Search value
    Node* newRoot = searchBSTRecursive(root, 30);

    // Print subtree if found
    if(newRoot){
        cout << "Subtree rooted at " << newRoot->data << ":\n";
        printLevelOrder(newRoot);
    } else {
        cout << "Value not found in BST\n";

    }
    cout<<"Iterative solution"<<endl;
    // Search value iteratiove
    Node* newRoot1 = searchBSTIterative(root, 30);

    // Print subtree if found
    if(newRoot1){
        cout << "Subtree rooted at " << newRoot1->data << ":\n";
        printLevelOrder(newRoot1);
    } else {
        cout << "Value not found in BST\n";
    }


}




