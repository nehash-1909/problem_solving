/*********************************************************************************************************************************
2. Reverse Link List II

Problem Description
Reverse a linked list A from position B to C.
NOTE: Do it in-place and in one-pass.
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
ListNode* reverseList(ListNode* head,int x)
{
    ListNode* cur = head;
    ListNode* prev = NULL;
    ListNode* nxt;

    ListNode* temp = head;

    for(int i=0;i<x;i++)
    {
        temp =temp->next;
    }
    temp = temp->next;
    for(int i=0;i<=x;i++)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head->next = temp;
    
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* head = A;
    ListNode* prev = new ListNode(-1);
    ListNode* temp = A;

    for(int i=0;i<B-1;i++)
    {
        prev = temp;
        temp =temp->next;
    }
    if(B==1)
    {
        A = reverseList(temp,C-B);
        return A;
    }
    prev->next = reverseList(temp,C-B);
    return A;
    
}
