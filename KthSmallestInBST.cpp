/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//in order is ok;

//
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	int cnt = count(root->left);
    	if(k <= cnt){
    		return kthSmallest(root->left, k);
    	}else if(k > cnt + 1){
    		return kthSmallest(root->right, k - cnt - 1);
    	}
    	return root->val;        
    }

    int count(TreeNode* root){
    	if(!root)return 0;
    	return 1 + count(root->left) + count(root->right);
    }
};


//modify the BST node's structure
class Solution {
public:
	struct MyTreeNode
	{
		int val;
		int count;
		MyTreeNode *left;
		MyTreeNode *right;
		MyTreeNode(int x):val(x),count(1),left(NULL),right(NULL){}
	};

	MyTreeNode* build(TreeNode* root){
		if(!root)return NULL;
		MyTreeNode *node = new MyTreeNode(root->val);
		node->left = build(node->left);
		node->right = build(node->right);
		if(node->left) node->count += node->left->count;
		if(node->right)node->count += node->right->count; 
		return node;
	}

    int kthSmallest(TreeNode* root, int k) {
    	MyTreeNode* newroot = build(root);
    	return helper(node, k);
			        
    }

    int helper(MyTreeNode* node, int k){
    	if(node->left){
    		int cnt = node->left->count;
    		if(k <= cnt){
    			return helper(node->left, k);
    		}else if(k > cnt + 1){
    			return helper(node->right, k - cnt - 1);
    		}
    		return node->val;
    	}else{
    		if(k == 1)return node->val;
    		return node(node->right , k - 1);
    	}
    }
};