#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void buildTreeLevelOrder(Node* &root){
    queue<Node*> q;
    int data;
    cout<<"Enter data for root:";
    cin>>data;
    root =  new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left for "<<temp->data<<":";
        int leftData;
        cin>>leftData;
         if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);   
        }


        cout<<"Enter right for "<<temp->data<<":";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);   
        }
    }
}


void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
       
        int size = q.size();

        for(int i = 0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
        cout<<endl;
    }
}


int main(){


    Node* root = NULL;

    buildTreeLevelOrder(root);
    levelOrder(root);

   

}