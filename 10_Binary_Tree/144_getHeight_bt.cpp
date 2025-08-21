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


int getHeightRecursive(Node* root){
    if(root==NULL){
        return 0;
    }


    int l = getHeightRecursive(root->left); 
    int r = getHeightRecursive(root->right);


    return max(l,r) + 1;




}

int getHeightIterative(Node* root){
    if(root==NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; i++){
             Node* temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        count++;
       

    }

    return count;
   
}


int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout<<"Total Height of Tree:"<<getHeightRecursive(root);
    cout<<endl;
    cout<<"Total Height of Tree:"<<getHeightIterative(root);


}