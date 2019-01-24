class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root)return NULL;
    	if(root->val > max(p->val, q->val))
    		return lowestCommonAncestor(root->left, p, q);
    	else if(root->val < min(p->val, q->val))
    		return lowestCommonAncestor(root->right, p, q);
    	else 
    		return root;
        
    }
};


//if not a BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
       if (left && right) return root;
       return left ? left : right;
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       if (left && left != p && left != q) return left;
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
　　　　if (left && right) return root;
       return left ? left : right;
    }
};
