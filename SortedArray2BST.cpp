/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size() - 1);
    }

    TreeNode* DFS(vector<int>& nums, int left, int right){
    	if(left > right)return NULL;
    	int mid = (left + right) / 2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = DFS(nums, left, mid - 1);
    	root->right = DFS(nums, mid + 1, right);
    	return root;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if(!head)return NULL;
    	if(!head->next)return new TreeNode(head->val);
    	ListNode* slow = head;
    	ListNode* fast = head;
    	ListNode* last = slow;
    	while(fast->next && fast->next->next){
    		last = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	fast = slow->next;
    	last->next = NULL;
    	TreeNode* root = new TreeNode(slow->val);
    	if(head != slow) root->left = sortedListToBST(head);
    	root->right = sortedListToBST(fast);
        return root;
    }  
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return helper(head, NULL);
    }
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *cur = new TreeNode(slow->val);
        cur->left = helper(head, slow);
        cur->right = helper(slow->next, tail);
        return cur;
    }
};