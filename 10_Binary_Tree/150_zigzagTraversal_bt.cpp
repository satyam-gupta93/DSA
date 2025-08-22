#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<Node*> q;
        q.push(root);
        bool LTR = true;  // Left to Right flag

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();

                // Insert at correct position
                if(LTR){
                    level[i] = temp->data;
                } else {
                    level[size - i - 1] = temp->data;
                }

                // Push children
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            // Flip direction
            LTR = !LTR;
            ans.push_back(level);
        }

        return ans;
    }


int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    
    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:"<<endl;
    for(auto &level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
