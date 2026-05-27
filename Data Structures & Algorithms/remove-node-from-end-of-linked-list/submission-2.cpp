/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0; 
        ListNode* iterate = head; 
        while(iterate != NULL)
        {
            iterate = iterate->next; 
            length++; 
        }   
        if(length == 1)
        {
            return NULL; 
        }
        int index = length - n; 
        if(index == 0)
        {
            head = head->next; 
            return head; 
        }
        iterate = head; 
        for(int i = 0; i < index - 1; i++)
        {
            iterate = iterate->next; 
        }
        iterate->next = iterate->next->next; 
        return head; 
    }
};
