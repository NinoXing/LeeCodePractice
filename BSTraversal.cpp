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
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int>res;
    	inorder(res,root);
    	return res;
    }
    void inorder(vector<int> &res, TreeNode* root){
    	if(root==NULL)return;
    	if(root->left)inorder(res,root->left);
    	res.push_back(root->val);
    	if(root->right)inorder(res,root->right);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};



//Recursive solution is trivial, could you do it iteratively?
//ues stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> s;
    	TreeNode *p = root;
    	while(p || !s.empty()){
    		while(p){
    			s.push(p);
    			p=p->left;
    		}
    		p = s.top();
    		s.pop();
    		res.push_back(p->val);
    		p=p->right;
    	}
    	return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> s;
    	TreeNode *p = root;
    	while(p || !s.empty()){
    		if(p){
    			s.push(p);
    			p=p->left;
    		}
    		else{
    			TreeNode *tmp = s.top();
    			s.pop();
    			res.push_back(tmp->val);
    			p = tmp->right
    		}
    	}
    	return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> s;
    	TreeNode *p = root;
    	while(p || !s.empty()){
    		if(p){
    			s.push(p);
    			res.push_back(p->val);
    			p=p->left;
    		}
    		else{
    			TreeNode *tmp = s.top();
    			s.pop();
    			p = tmp->right;
    		}
    	}
    	return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> s;
    	TreeNode *p = root;
    	while(p || !s.empty()){
    		if(p){
    			s.push(p);
    			res.insert(res.begin(),p->val);
    			p=p->right;
    		}
    		else{
    			TreeNode *tmp = s.top();
    			s.pop();
    			p = tmp->left;
    		}
    	}
    	return res;
    }
};

//Morris Traversal
//螺旋二叉树，当前节点p的右子节点指向p在中序遍历的下一个节点，p的左节点指向p在中序遍历的前一个节点。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur=root;
        TreeNode *pre;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val)
                cur=cur->right;
            }
            else{
                pre=cur->left;
                while(pre->right && pre->right!=cur){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=cur;
                    cur=cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};






















