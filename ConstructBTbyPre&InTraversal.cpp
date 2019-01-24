class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeDFS(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeDFS(vector<int>& preorder, int pleft, int pright, vector<int> &inorder, int ileft, int iright){
    	if(pleft > pright || ileft > iright) return NULL;
    	int i = 0;
    	for(int i = ileft; i <= iright; ++i){
    		if(preorder[pleft] == inorder[i]) break;
    	}
    	TreeNode* cur = new TreeNode(preorder[pleft]);
    	cur->left = buildTreeDFS(preorder, pleft+1, pleft + i - ileft, inorder, ileft, i-1);
    	cur->right = buildTreeDFS(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
    	return cur;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};