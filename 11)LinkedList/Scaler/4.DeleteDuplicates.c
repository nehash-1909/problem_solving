/*********************************************************************************************************************************
4.Remove Duplicates from Sorted List

Problem Description
Given a sorted linked list, delete all duplicates such that each element appears only once.
*********************************************************************************************************************************/
// Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* cur = A;
    ListNode* nxt = A->next;
    while(nxt)
    {
        if(cur->val == nxt->val)
        {
            cur->next = nxt->next;
        }
        else
        {
            cur = cur->next;
        }
        nxt = nxt->next;
    }
    return A;
}

