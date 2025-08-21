#include<iostream>
#include<stack>
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

void postOrderRecursive(Node* root){
    if(root==NULL){
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout<<root->data<<" ";
}

void postOrderIterative(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node*> st;
    Node* curr = root;
    Node* visited = NULL;
    while(curr!=NULL || !st.empty() ){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
    

    curr = st.top();

    if(curr->right!= NULL && visited!= curr->right ){
        curr = curr->right;
    }else{
        
        cout<<curr->data<<" ";
        st.pop();
        visited = curr;
        curr = NULL;

    }

    }

}

void postOrderTwoStack(Node* root){
    if(root==NULL){
        return;
    }

    stack<Node*> st1,st2;
    st1.push(root);
   

    while(!st1.empty()){
         Node* curr = st1.top();
         st1.pop();

         st2.push(curr);

         if(curr->left!=NULL){
            st1.push(curr->left);
         }
         if(curr->right!=NULL){
            st1.push(curr->right);
         }
    }

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }


}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
   // root->right->right = new Node(6);

    cout<<"PostOrder -> ";
    postOrderRecursive(root);
    
    cout<<endl;
    cout<<"PostOrder -> ";
     postOrderIterative(root);

     cout<<endl;
    cout<<"PostOrder -> ";
     postOrderTwoStack(root);


   

}