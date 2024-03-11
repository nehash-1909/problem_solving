/*********************************************************************************************************************************
1. K reverse linked list

Problem Description

Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return the modified linked list.
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
ListNode* reverse(ListNode* A)
{
    ListNode* cur = A;
    ListNode* prev = NULL;
    ListNode* nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B==1)
    {
        return A;
    }
    ListNode* head = A;
    ListNode* rhead = A;
    ListNode* prev;
    while(head!=NULL && head->next!=NULL)
    {
        ListNode* start = head;
        ListNode* tail = start;
        int i =0;
        while(tail!=NULL && i<B-1)
        {
            tail = tail->next;
            i++;
        }
        ListNode* temp = tail->next;
        tail->next = NULL;
        ListNode* node = reverse(start);
        
        if(rhead == A)
        {
            rhead = node;
        }
        else
        {
            prev->next = node;
        }
        while(node->next!=NULL)
        {
            node = node->next;
        }
        prev = node;
        head = temp;
        
    }
    return rhead;
}
