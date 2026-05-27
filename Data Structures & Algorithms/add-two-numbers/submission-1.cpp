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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = NULL; 
        ListNode* start; 
        int addNext = 0; 
        int count = 0; 
        while(l1 != NULL || l2 != NULL)
        {
            int num = 0; 
            if(l1 != NULL)
            {
                num += l1->val;
                l1 = l1->next;  
            }
            if(l2 != NULL)
            {
                num += l2->val; 
                l2 = l2->next;
            }
            num += addNext; 
            if(num > 9)
            {
                addNext = num/10; 
                num = num%10; 
            }
            else 
            {
                addNext = 0; 
            }
            if(count == 0)
            {
                curr = new ListNode(num); 
                start = curr; 
            }
            else 
            {
                curr->next = new ListNode(num); 
                curr = curr->next;  
            }
            count++;  
        }
        if(addNext != 0)
        {
            curr->next = new ListNode(addNext); 
        }
        return start; 
    }
};
