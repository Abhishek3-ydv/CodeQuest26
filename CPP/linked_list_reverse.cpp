#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || k = 1) return head; 
    Node* dummy = new Node();
    dummy->next = head;
    Node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while(curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    while(count > k) { 
        curr = pre->next;
        nex = curr->next;
        for(int i=1; i<=k; i++) { 
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next 
        }
        pre = curr;
        count -= k;
    }
    return head; 
}