#include<iostream> 
using namespace std;

class Node{
   
public:
    int data;
    Node* left =NULL;
    Node* right=NULL;    


    Node(int data){
        this->data = data;
    }
};

int totalNodes(Node* root){

    if(root==NULL){
        return 0;
    }

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}


bool checkCompleteTree(Node* root,int i, int total){

    if(root==NULL){
        return true;
    }

    if(i>=total){
        return false;
    }


    return checkCompleteTree(root->left,2*i+1,total) && checkCompleteTree(root->right,2*i+2,total);


}

bool checkHeapProperty(Node* root){

    if(root->left==NULL && root->right == NULL){
        return true;
    }

    if(root->left && root->right==NULL){
        return root->data>=root->left->data && checkHeapProperty(root->left);
    }

    if(root->left!=NULL && root->right!=NULL){
        return (root->data>=root->left->data) && (root->data>=root->right->data) && checkHeapProperty(root->left) && checkHeapProperty(root->right);
    }

    return false;


}

bool checkHeap(Node* tree){
    int total = totalNodes(tree);

    return checkCompleteTree(tree,0,total) && checkHeapProperty(tree);
}


int main(){
    
     /*
              10
             /  \
            9    8
           / \  /
          7  6 5
    */
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if (checkHeap(root))
        cout << "Tree is a Max Heap\n";
    else
        cout << "Tree is not a Heap\n";

    return 0;

}