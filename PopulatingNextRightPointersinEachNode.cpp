/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;

        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	for(int i = 0; i < size; ++i){
        		TreeLinkNode* fast = q.front();
        		q.pop();
        		if(i < size - 1)fast->next = q.front();
        		if(fast->left)q.push(fast->left);
        		if(fast->right)q.push(fast->right);
        	}
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;
    	TreeLinkNode* start = root;
    	TreeLinkNode* cur = NULL;
    	while(start->left){
    		cur = start;
    		while(cur){
    			cur->left->next = cur->right;
    			if(cur->next)cur->right->next = cur->next->left;
    			cur = cur->next;
    		}
    		start = start->left;
    	}
    }
};