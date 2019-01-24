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
    bool isValidBST(TreeNode* root) {
    	stack<TreeNode*> s;
    	TreeNode* p = root;
    	TreeNode* pre = NULL;
    	while(p || !s.empty()){
    		while(p){
    			s.push(p);
    			p = p->left;
    		}
    		TreeNode* tmp = s.top();
    		s.pop();
    		if(pre && pre->val >= tmp->val) return false;
    		pre = tmp;
    		p = tmp->right;
    	}
    	return true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long min, long max){
    	if(!root)return true;
    	if(root->val <= min || root->val >= max)return false;
    	return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

//isSameTree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(p == NULL && q == NULL)return true;
    	if(p == NULL || q == NULL)return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
        	TreeNode* tmp1 = q1.front();
        	TreeNode* tmp2 = q2.front();
        	q1.pop();
        	q2.pop();
        	if(tmp1->val != tmp2->val)return false;
        	if((tmp1->left == NULL && tmp2->left != NULL)||(tmp2->left == NULL && tmp1->left != NULL))return false;
        	if(tmp1->left != NULL && tmp2->left != NULL){
        		q1.push(tmp1->left);
        		q2.push(tmp2->left);
        	}
         	if((tmp1->right == NULL && tmp2->right != NULL)||(tmp2->right == NULL && tmp1->right != NULL))return false;
        	if(tmp1->right != NULL && tmp2->right != NULL){
        		q1.push(tmp1->right);
        		q2.push(tmp2->right);
        	}       	
        }
        if(q1.empty() && q2.empty())return true;
        else
        	return false;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(!root)return true;
        if(!root->left && !root->right)return true;
        return isSymmetricDFS(root->left, root->right);

    }
    bool isSymmetricDFS(TreeNode* leftnode, TreeNode* rightnode){
    	if(!leftnode && !rightnode)return true;
    	if((!leftnode && rightnode)||(leftnode && !rightnode)||(leftnode->val != rightnode->val))return false;
    	return isSymmetricDFS(leftnode->left, rightnode->right) && isSymmetricDFS(leftnode->right, rightnode->left);
    }
};
