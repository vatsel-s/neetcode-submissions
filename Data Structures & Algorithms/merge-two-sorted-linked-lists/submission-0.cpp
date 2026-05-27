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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
            return list2; 
        }
        else if(list2 == NULL)
        {
            return list1; 
        }
        ListNode* start; 
        if(list1->val < list2->val)
        {
            start = list1; 
            list1 = list1->next; 
        } 
        else 
        {
            start = list2; 
            list2 = list2->next; 
        }
        ListNode* iterate = start; 
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                iterate->next = list1; 
                list1 = list1->next; 
            }
            else 
            {
                iterate->next = list2;
                list2 = list2->next;  
            }
            iterate = iterate->next; 
        }
        if(list1 != NULL)
        {
            iterate->next = list1; 
        }
        else 
        {
            iterate->next = list2; 
        }
        return start; 
    }
};
