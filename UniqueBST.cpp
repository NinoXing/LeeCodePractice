//https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
//卡塔兰数

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> nope;
        if(n==0)return npoe;
        else
            return genBST(1,n)
    }
    vector<TreeNode*> genBST(int min, int max,){
        vector<TreeNode*> res;
        if(min>max){
            res.push_back(NULL);
            return res;
        }
        for(int i=min; i<=max; i++){
            vector<TreeNode*> LeftTree = genBST(min,i-1);
            vector<TreeNode*> RightTree = genBST(i+1,max);
            for(int j=0; j<LeftTree.size(); j++){
                for(int k=0; k<RightTree.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = LeftTree[j];
                    root->right = RightTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};