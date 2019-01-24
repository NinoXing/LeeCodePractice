/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Reverse a singly linked list.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(!head)return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while(cur->next){
        	ListNode* tmp = cur->next;
        	cur->next = tmp->next;
        	tmp->next = dummy->next;
        	dummy->next = tmp;
        }
        return dummy->next;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(!head || !head->next)return head;
    	ListNode* p = head;
    	head = reverseList(p->next);
    	p->next->next = p;
    	p->next = NULL;
    	return head;
    }
};




//Reverse a linked list from position m to n. Do it in one-pass.
//Input: 1->2->3->4->5->NULL, m = 2, n = 4
//Output: 1->4->3->2->5->NULL
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m<1 || m>=n || !head)return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* BeforeReverse = dummy;
        ListNode *pre, *cur;
        for(int i = 0; i < m - 1; ++i){
        	BeforeReverse = BeforeReverse->next;
        }
        pre = BeforeReverse->next;
        cur = pre->next;
        for(int i = 0; i< n - m; ++i){
        	ListNode *tmp = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = tmp;
        }
        BeforeReverse->next->next = cur;
        BeforeReverse->next = pre;
        return dummy->next;
    }
};