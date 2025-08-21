#include<iostream>
using namespace std;
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };



Node *removeLoop(Node *head)
{
     if(head==NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;


            if(slow==fast){
               
                break;
            }


        }

        if(slow!=fast){
            return head;
        }
         slow = head;
                while(slow!=head){
                    slow = slow->next;
                    fast = fast->next;
                }
        
        while(fast->next!=slow){
            fast = fast->next;
        }
        fast->next= NULL;
        return head;
}