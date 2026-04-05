# https://leetcode.com/problems/merge-two-sorted-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        inicio = ListNode()
        prox = inicio

        while list1 and list2:
            if list1.val < list2.val:
                prox.next = list1
                list1 = list1.next
            else:
                prox.next = list2
                list2 = list2.next
                
            prox = prox.next

        prox.next = list1 if list1 else list2

        return inicio.next
