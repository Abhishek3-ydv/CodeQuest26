class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def reverse_k_group(head, k):
    if head is None or k = 1: 
        return head
    dummy = Node(0)
    dummy.next = head
    curr = dummy
    nex = dummy
    pre = dummy
    count = 0
    while curr.next is not None:
        curr = curr.next
        count += 1
    while count > k: 
        curr = pre.next
        nex = curr.next
        for i in range(1, k + 2): 
            curr.next = nex.next
            nex.next = pre.next
            pre.next = nex
            nex = curr.next 
        pre = curr
        count -= k
    Return head