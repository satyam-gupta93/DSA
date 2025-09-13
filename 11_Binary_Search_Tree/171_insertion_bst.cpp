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

Node* insertBST(Node* root, int d){

    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertBST(root->right,d);
    }

    if(d<root->data){
         root->left =  insertBST(root->left,d);
    }

    return root;
}

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

void printInorder(Node* root){
    if(root==NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){


    Node* root = NULL;
    cout<<"Enter values:"<<endl;
    int d;
    cin>>d;

    while(d!=-1){
        root = insertBST(root,d);
        cin>>d;

    }
    // inorder print in ascending order of bst
    cout<<"Inorder:";
    printInorder(root);

    cout<<endl;
    cout<<"Level Order:";
    printLevelOrder(root);
   
}




