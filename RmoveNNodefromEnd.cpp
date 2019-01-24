/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL)return NULL;
        ListNode* target = head;
        ListNode* cur = head;
        for (int i=0 ; i<n ; ++i){
        	cur = cur->next;
        }
        if(cur == NULL)return head->next;
        while(cur->next){
        	cur = cur->next;
        	target = target->next;
        }
        target->next = target->next->next;
        return head;

    }
};
