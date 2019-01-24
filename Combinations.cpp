using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n == 0 || k == 0)return {};
        vector<int> out;
        combineDFS(n,k,1,out,res);
        return res;
    }
    void combineDFS(int n, int k, int start, vector<int>& out, vector<vector<int>>& res){
    	if(out.size() == k){
    		res.push_back(out);
    		return;
    	}
    	for(int i = start; i<=n; ++i ){
    		out.push_back(i);
    		combineDFS(n,k,i+1,out,res);
    		out.pop_back();
    	}
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	if(nums.size() == 0)return {};
    	sort(nums.begin(),nums.end());
    	vector<vector<int>> res;
    	vector<int> out;
    	subsetsDFS(0,nums,out,res);
    	return res;
    }
    void subsetsDFS(int start, vector<int> &nums, vector<int> &out, vector<vector<int>> &res){
    	res.push_back(out);
    	for(int i = start; i<nums.size(); i++){
    		if(i>0 && nums[i]==nums[i-1] && i>start)continue;
    		out.push_back(nums[i]);
    		subsetsDFS(i + 1, nums, out, res);
    		out.pop_back();
    	}
    }
};
