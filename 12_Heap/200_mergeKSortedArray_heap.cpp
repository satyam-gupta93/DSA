#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
 public:
    int data;
    int i;
    int j;

    Node(int d,int row,int col){
        data = d;
        i = row;
        j = col;
    }
};

class compare{
 public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }

};

vector<int> mergeKSortedArrays(vector<vector<int>> arr,int k){

    priority_queue<Node*,vector<Node*>,compare> mini;
    vector<int> res;

    for(int i = 0; i<k; i++){
        mini.push(new Node(arr[i][0],i,0));
    }

    while(!mini.empty()){
        Node* curr = mini.top();
        mini.pop();

        res.push_back(curr->data);

        int row = curr->i;
        int col = curr->j;

        if(col + 1 < arr[row].size()){
            mini.push(new Node(arr[row][col+1],row,col+1));
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    int k = arr.size();

    vector<int> merged = mergeKSortedArrays(arr, k);

    cout << "Merged Array: ";
    for (int x : merged) cout << x << " ";
    cout << endl;

    return 0;
}