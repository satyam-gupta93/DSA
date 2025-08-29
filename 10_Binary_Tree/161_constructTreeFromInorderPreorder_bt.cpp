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




// another approach
void levelOrderTraversal1(Node *root){
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
    // we can use map also for o(1) optimiztion 
    //     void mapNode( map<int,int> &nodeIndex,vector<int>& inorder,int n){

    //     for(int i = 0; i<n; i++){
    //         nodeIndex[inorder[i]] = i;
    //     }
    // }
    int findPosi(vector<int> &inorder,int ele,int n){
        for(int i = 0; i<n; i++){
            if(inorder[i]==ele){
                return i;
            }
            
            
        } 
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder,int &preIndx,int inStart,int inEnd,int n){
        if(preIndx>=n || inStart > inEnd){
            return NULL;
        }
        
        int ele = preorder[preIndx++];
        Node* root = new Node(ele);
        
        int inPosi = findPosi(inorder,ele,n);
        
        root->left = solve(inorder,preorder,preIndx,inStart,inPosi-1,n);
        root->right = solve(inorder,preorder,preIndx,inPosi+1,inEnd,n);
        
        
        return root;
        
        
}
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preIndx = 0;
        int inStart = 0;
        int n = inorder.size();
        int inEnd = n - 1;
        
        return solve(inorder,preorder,preIndx,inStart,inEnd,n);
    }


int main(){

    vector<int> inOrder = {1, 6, 8, 7};
    vector<int> postOrder = {1, 6, 7, 8};

    Node* root =  buildTree(inOrder,postOrder);

    levelOrderTraversal1(root);

}



