#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* next = NULL;

    Node(int data){
        this->data = data;
    }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};


Node* mergeKLists(vector<Node*> lists){
    
    priority_queue<Node*,vector<Node*>,compare> mini;

    for(int i = 0; i<lists.size(); i++){
        if (lists[i] != NULL) {
            mini.push(lists[i]);
        }
    }
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(!mini.empty()){

        Node* curr = mini.top();
        mini.pop();

        tail->next = curr;
        tail = curr;

        if(curr->next){
            mini.push(curr->next);
        }

    }

    Node* head = dummy->next;
    delete dummy;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // List 1: 1 -> 4 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    // List 2: 1 -> 3 -> 4
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    // List 3: 2 -> 6
    Node* l3 = new Node(2);
    l3->next = new Node(6);

    // Put lists into vector
    vector<Node*> lists = {l1, l2, l3};

    Node* mergedHead = mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(mergedHead);

}