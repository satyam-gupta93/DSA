#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);

        if (len2 > len1) swap(l1, l2); // ensure l1 is longer

        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            carry = sum / 10;
            l1->val = sum % 10;

            prev = l1;
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry) prev->next = new ListNode(carry);

        return head;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Manually create first list: 4 -> 5 -> 6
    ListNode* l1 = new ListNode(4);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(6);

    // Manually create second list: 7 -> 8 -> 9
    ListNode* l2 = new ListNode(7);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(9);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
