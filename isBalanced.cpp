class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(abs(depth(root->right) - depth(root->left)) > 1)return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
    int depth(TreeNode* root){
        if(!root)return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if(check(root) == -1)return false;
    	else return true;
    }
    int check(TreeNode* root){
        if(!root)return 0;
        int left = check(root->left);
        if(left == -1) return -1;
        int right = check(root->right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return - 1;
        else return 1 + max(left, right);
    }
};