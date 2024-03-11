/*********************************************************************************************************************************
3.Remove Nth Node from List End
Problem Description

Given a linked list A, remove the B-th node from the end of the list and return its head.
For example, given linked list: 1->2->3->4->5, and B = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list. Try doing it using constant additional space.
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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A->next == NULL && B == 1) 
    {
        return NULL;
    }
    ListNode* temp = A;
    int i = 0;
    ListNode* p;
    while(temp->next!=NULL)
    {
        p = temp;
        temp = temp->next;
        i++;
    }
    if(B==1)
    {
        p->next = NULL;
        return A;
    }
    if(i<B)
    {
        return A->next;
    }

    int delete_node = i - B + 1;
    
    if(delete_node == 1)
    {
        return A->next;
    }
    ListNode* prev = NULL;
    temp = A;
    for(int j = 1;j<=delete_node;j++)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp->next !=NULL)
        prev->next = temp->next;
    else
        prev->next = NULL;
    free(temp);
    return A;
}
