class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        pathSumDFS(root, sum, out, res);
        return res;
    }
    void pathSumDFS(TreeNode* root, int target, vector<int> &out, vector<vector<int>> &res){
    	if(!root){
    		return;
    	}
    	out.push_back(root->val);
    	if(target == root->val && !root->left && !root->right){
    		res.push_back(out);
    	}
    	pathSumDFS(root->left, target-root->val, out, res);
    	pathSumDFS(root->right, target-root->val, out, res);
    	out.pop_back();
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int &res){
        if(!node)return 0;
        int left = max(helper(node->left, res), 0);
        int right = max(helper(node->right, res), 0);
        res = max(right + left + node->val, res);
        return max(left, right) + node->val;
    }
};

//129. Sum Root to Leaf Numbers
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumDFS(root, 0);
    }
    int sumDFS(TreeNode* root, int sum){
        if(!root)return 0;
        sum = sum*10 + root->val;
        if(!root->left && !root->right)return sum;
        return sumDFS(root->left, sum) + sumDFS(root->right, sum);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(!root)return res;
        sumDFS(root, res, 0)
        return res;
    }
    void sumDFS(TreeNode* root, int &res, int cur){
        cur = cur*10 + root->val;
        if(!root->left && !root->right)sum += cur;
        if(root->left)sumDFS(root->left, res, cur);
        if(root->right)sumDFS(root->right, res, cur);
    }
};