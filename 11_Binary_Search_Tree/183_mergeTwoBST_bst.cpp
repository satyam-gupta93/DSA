// approch 1 - 

// TC - O(n+m)
// sc - o(n+m)

// #include <iostream>
// #include <vector>
// #include<queue>
// using namespace std;


// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// void levelOrder(Node* root) {
//     if (!root) return;
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()) {
//         int size = q.size();
//         while(size--) {
//             Node* node = q.front();
//             q.pop();
//             cout << node->data << " ";
//             if(node->left) q.push(node->left);
//             if(node->right) q.push(node->right);
//         }
//         cout << endl;
//     }
// }

// void findInorder(Node* root, vector<int>& inorder) {
//     if (root == NULL) return;
//     findInorder(root->left, inorder);
//     inorder.push_back(root->data);
//     findInorder(root->right, inorder);
// }


// Node* inorderToBST(int s, int e, vector<int>& inorder) {
//     if (s > e) return NULL;

//     int mid = s + (e - s) / 2;
//     Node* newRoot = new Node(inorder[mid]);

//     newRoot->left = inorderToBST(s, mid - 1, inorder);
//     newRoot->right = inorderToBST(mid + 1, e, inorder);

//     return newRoot;
// }


// void mergeToSorted(vector<int> inroot1,vector<int> inroot2,vector<int> &ans){
        
//         int i = 0;
//         int j = 0;
//         int k = 0;
//         int n = inroot1.size();
//         int m = inroot2.size();
        
        
//         while(i<n  && j<m){
            
//             if(inroot1[i]<inroot2[j]){
//                 ans.push_back(inroot1[i++]);
//             }else{
//                  ans.push_back(inroot2[j++]);
//             }
//         }
        
//         if(i<n){
//             while(i<n){
//                 ans.push_back(inroot1[i++]);
//             }
//         }
//         if(j<m){
//              while(j<m){
//                 ans.push_back(inroot2[j++]);
//             }
//         }
        
        
        
//  }


//      Node* merge(Node *root1, Node *root2) {
//         // Your code here
        
//         vector<int> inroot1;
//         vector<int> inroot2;
         
         
//           findInorder(root1,inroot1);
//           findInorder(root2,inroot2);
         
         
//          vector<int> ans;
         
         
         
//          mergeToSorted(inroot1,inroot2,ans);
         
         
//         Node* root = inorderToBST(0,ans.size()-1,ans);

//          return root;
         
         
         
         
         
//     }


// int main() {
//  // First BST
//     Node* root1 = new Node(2);
//     root1->left = new Node(1);
//     root1->right = new Node(4);

//     // Second BST
//     Node* root2 = new Node(9);
//     root2->left = new Node(3);
//     root2->right = new Node(12);


//     cout<<"Level order BST-1:"<<endl;
//     levelOrder(root1);

//     cout<<"Level order BST-2:"<<endl;
//     levelOrder(root2);

//     // Merge the two BSTs
//     Node* mergedRoot = merge(root1, root2);

//     cout << "Level Order Traversal of Merged Balanced BST:\n";
//     levelOrder(mergedRoot);

//     return 0;




// }


// approach 2 

// TC - O(N+M)
// sc - o(h1+h2)


#include <iostream>
#include <queue>
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


void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}


Node* bstToLL(Node* root, Node*& prev) {
    if (!root) return NULL;

    Node* head = bstToLL(root->left, prev);

    if (!prev) head = root;
    else prev->right = root;

    prev = root;
    root->left = NULL;

    bstToLL(root->right, prev);
    return head;
}


Node* mergeTwoLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2 = head2->right;
        }
        tail = tail->right;
        tail->left = NULL;
    }

    if (head1) tail->right = head1;
    if (head2) tail->right = head2;

    Node* head = dummy->right;
    delete dummy;
    return head;
}


Node* curr; // global pointer for current node in LL

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->right;
    }
    return len;
}

Node* sortedLLToBST(int n) {
    if (n <= 0) return NULL;

    Node* left = sortedLLToBST(n / 2);

    Node* root = curr;
    root->left = left;

    curr = curr->right;

    root->right = sortedLLToBST(n - n / 2 - 1);

    return root;
}


Node* merge(Node* root1, Node* root2) {
    Node* prev = NULL;
    Node* head1 = bstToLL(root1, prev);

    prev = NULL;
    Node* head2 = bstToLL(root2, prev);

    Node* mergedHead = mergeTwoLL(head1, head2);

    curr = mergedHead;
    int totalNodes = getLength(mergedHead);

    return sortedLLToBST(totalNodes);
}

// -------- Main --------
int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    cout << "Level order BST-1:\n";
    levelOrder(root1);

    cout << "Level order BST-2:\n";
    levelOrder(root2);

    Node* mergedRoot = merge(root1, root2);

    cout << "Level Order Traversal of Merged Balanced BST:\n";
    levelOrder(mergedRoot);

    return 0;
}
