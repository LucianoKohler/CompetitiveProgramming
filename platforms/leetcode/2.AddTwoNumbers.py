# https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = 0
        digits = 1
        while l1:
            n1+=l1.val*digits
            digits*=10
            l1 = l1.next

        n2 = 0
        digits = 1
        while l2:
            n2+=l2.val*digits
            digits*=10
            l2 = l2.next
        
        n3 = list(str(n1+n2))[::-1]
        l3 = ListNode(0)
        atual = l3

        for i in range(0, len(n3)):
            atual.next = ListNode(int(n3[i]))
            atual = atual.next
        
        return l3.next
