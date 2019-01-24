/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//使用merge 排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next)return head;
        ListNode *fast = head, *slow = head, *pre = head;
        while(fast && fast->next){
        	pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }

private:
	ListNode* merge(ListNode* left, ListNode* right){
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while(left && right){
			if(left->val < right->val){
				cur->next = left;
				left = left->next;
			}else {
				cur->next = right;
				right = right->next;
			}
			cur = cur->next;
		}
		if(left)cur->next = left;
		if(right)cur->next = right;
		return dummy->next;
	}
};