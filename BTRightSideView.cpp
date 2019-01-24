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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};

        vector<int> res;
        queue<TreeNode*> bt;

        bt.push(root);
        
        while(!bt.empty()){
        	int size = bt.size();
        	for(int i = 0; i < size; i++){
        		TreeNode *node = bt.front();
        		if(i == size - 1)res.push_back(node->val);
        		bt.pop();
        		if(node->left != NULL){
        			bt.push(node->left);
        		}
        		if(node->right != NULL){
        			bt.push(node->right);
        		}
        	}
        }
        return res;
    }
};