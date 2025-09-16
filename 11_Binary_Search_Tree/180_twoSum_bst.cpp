#include <iostream>
#include <climits>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void findInorder(Node* root, vector<int> &inorder){
    if(root==NULL){
        return;
    }

    findInorder(root->left,inorder);
    inorder.push_back(root->data);
    findInorder(root->right,inorder);
}

bool twoSum(Node* root,int k){
    if(root==NULL){
        return false;
    }

    vector<int> inorder;

    findInorder(root,inorder);

    int i = 0;
    int j = inorder.size() - 1;

    while(j>i){

        if(inorder[i]+inorder[j]==k){
            return true;
        }else if(inorder[i]+inorder[j]<k){
            i++;
        }else{
            j--;
        }
    }

    return false;
}

int main() {
    // Example Tree
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    cout<<"Check Two Sum:"<<twoSum(root,12);
    return 0;



    // Time Complexity (TC):O(n)
    //     O(n) (inorder traversal) + O(n) (two-pointer scan) = O(n)

    // Space Complexity (SC):O(n)
    //     O(n) for storing inorder traversal
    //     O(h) recursion stack (h = tree height, worst case O(n) for skewed tree)
    //     So overall O(n) space
}
