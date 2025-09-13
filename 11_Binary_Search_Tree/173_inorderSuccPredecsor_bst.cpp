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

Node* findMin(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }

    return root;
}
Node* findMax(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL && root->right!=NULL){
        root = root->right;
    }

    return root;
}

Node* inorderSuccessor(Node* root,Node* target){
    if(target->right!=NULL){
        return findMin(target->right);
    }

    Node* succ = NULL;
    while(root!=NULL){
        if(target->data<root->data){
            succ = root;
            root = root->left;
        }else if(target->data>root->data){
            root = root->right;
        }else{
            break;
        }
    }

    return succ;
}
Node* inorderPredecessor(Node* root,Node* target){
    if(target->left!=NULL){
        return findMax(target->left);
    }

    Node* pred = NULL;
    while(root!=NULL){
        if(target->data<root->data){
           
            root = root->left;
        }else if(target->data>root->data){
            pred = root;
            root = root->right;
        }else{
            break;
        }
    }
    return pred;
}

int main(){


    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

     
    Node* succ = inorderSuccessor(root, root->right->left);
    Node* pred = inorderPredecessor(root,root->right->left);


    cout << "Inorder Successor: " << succ->data<< endl;
    cout << "Inorder Predecessor: " << pred->data<< endl;




}




