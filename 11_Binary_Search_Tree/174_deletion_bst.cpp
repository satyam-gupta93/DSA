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
        return root;
    }

    while(root && root->left!=NULL){
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return root;
    }

    if(root->data<key){
        root->right = deleteNode(root->right,key);
    }else if(root->data>key){
       root->left =  deleteNode(root->left,key);
    }else{ // equal


        // case - 1 NO children leaf node
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // case - 2 only one child
        else if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // case - 2 only one child
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case - 3 two child
        else{

            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right,successor->data);
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
      root->right->right->right = new Node(100);


    cout<<"Before Deletion->>"<<endl;
    printLevelOrder(root);

    root = deleteNode(root,50);
    cout<<"After Deletion->>"<<endl;
    printLevelOrder(root);





}




