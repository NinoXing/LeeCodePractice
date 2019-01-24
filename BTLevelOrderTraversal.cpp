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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)return {};

        vector<vector<int>> res;
        queue<TreeNode*> bt;

        bt.push(root);
        
        while(!bt.empty()){
        	int size = bt.size();
        	vector<int> out;
        	for(int i = 0; i < size; i++){
        		TreeNode *node = bt.front();
        		out.push_back(node->val);
        		bt.pop();
        		if(node->left != NULL){
        			bt.push(node->left);
        		}
        		if(node->right != NULL){
        			bt.push(node->right);
        		}
        	}
        	res.push_back(out);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode *root, int level, vector<vector<int> > &res) {
        if (!root) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, res);
        if (root->right) levelorder(root->right, level + 1, res);
    }
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >res;
        if (!root) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        vector<int> out;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode *cur = s1.top();
                s1.pop();
                out.push_back(cur->val);
                if (cur->left) s2.push(cur->left);
                if (cur->right) s2.push(cur->right);
            } 
            if (!out.empty()) res.push_back(out);
            out.clear();
            while (!s2.empty()) {
                TreeNode *cur = s2.top();
                s2.pop();
                out.push_back(cur->val);
                if (cur->right) s1.push(cur->right);
                if (cur->left) s1.push(cur->left);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
        }
        return res;
    }
};


//topological sorting
//207
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if(prerequisites.size()==1)return true;

        vector<unordered_set<int>> graph(numCourses,unordered_set<int>());
        //vector<bool> iflow(numCourses,true);
        vector<int> indgree(numCourses,0);
        queue<int> bfs;

        for(auto a:prerequisites){
        	graph[a.second].insert(a.first);
        	indgree[a.first]++;
        }

        for(int i = 0; i < numCourses ; i++){
        	if(indgree[i] == 0)bfs.push(i);
        }

        while(!bfs.empty()){
        	int node = bfs.front();
        	bfs.pop();
        	for(auto a:graph[node]){
        		--indgree[a];
        		if(indgree[a] == 0)bfs.push(a);
        	}
        }
        for(int i = 0; i < numCourses; i++){
        	if(indgree[i] != 0)return false;
        }
        return true;
    }

};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;

        vector<unordered_set<int>> graph(numCourses,unordered_set<int>());
        //vector<bool> iflow(numCourses,true);
        vector<int> indgree(numCourses,0);
        queue<int> bfs;

        for(auto a:prerequisites){
            graph[a.second].insert(a.first);
            indgree[a.first]++;
        }

        for(int i = 0; i < numCourses ; i++){
            if(indgree[i] == 0)bfs.push(i);
        }

        while(!bfs.empty()){
            int node = bfs.front();
            res.push_back(node);
            bfs.pop();
            for(auto a:graph[node]){
                --indgree[a];
                if(indgree[a] == 0)bfs.push(a);
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(indgree[i] != 0)return {};
        }
        return res;
    }
};












