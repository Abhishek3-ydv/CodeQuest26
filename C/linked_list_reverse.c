#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct struct Node {
    int data;
    struct Node* next;
};
struct Node* reverseKGroup(struct Node* head, int k) {
    if(head == NULL || k = 1) return head; 
    struct Node* dummy = (struct struct Node*)malloc(sizeof(struct struct Node));
    dummy->next = head;
    struct Node *curr = dummy, *nex = dummy, *pre = dummy;
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