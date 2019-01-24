/*Swap Nodes in Pairs 
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//双指针做法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    	ListNode* res = new ListNode(-1);
    	res->next = head;
    	ListNode* pre = res;
    	while(pre->next && pre->next->next){
    		ListNode *tmp = pre->next->next;
    		pre->next->next = tmp->next;
    		tmp->next = pre->next;
    		pre->next = tmp;
    		pre = tmp->next;
    	}
        return res->next;
    }
};

//迭代

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    	if(!head || !head->next) return head;
    	ListNode* tmp = head->next;
    	head->next = swapPairs(head->next->next);
    	tmp->next = head;
    	return tmp;
    }
};
///////////////////////////////////////////////////////////////////////////
//reverse every K node in a list
class Solution {
public:

//首先解决问题：如何reverse一个list:
    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }

//再每k段调用

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        ListNode* cur = head;
        dummy->next = head;
        int i = 0;
        while(cur){
        	i++;
        	if(i%k == 0){
        		pre = reverseOneGroup(pre , cur->next);
        		cur = pre->next;
        	}
        	else{
        		cur = cur->next;
        	}
        }
        return dummy->next;
    }
};

//递归解法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};







