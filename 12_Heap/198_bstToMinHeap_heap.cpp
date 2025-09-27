#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left = NULL;
        Node* right = NULL;


        Node(int data){
            this->data = data;
        }
};

void inorder(Node* root, vector<int> &arr){

    if(root==NULL){
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void fillPredorder(Node* root,vector<int> &arr,int &indx){
    if(root==NULL){
        return;
    }
    root->data = arr[indx++];
    fillPredorder(root->left,arr,indx);
    fillPredorder(root->right,arr,indx);
}
void bstToMinHeap(Node* root){
    if(root==NULL){
        return ;
    }
    vector<int> arr;

    inorder(root,arr);
    int index= 0;

    fillPredorder(root,arr,index);


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


     /*
           4
         /   \
        2     6
       / \   / \
      1  3  5   7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"Before--->"<<endl;
    levelOrder(root);
    bstToMinHeap(root);

    cout << "Level Order of Min Heap: "<<endl;
    levelOrder(root);  // To verify
}