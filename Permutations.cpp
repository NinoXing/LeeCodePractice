class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>>res;
    	//if(nums.size()==0)return res;
    	vector<int> out;
    	sort(nums.begin(),nums.end());
    	vector<int> visited(nums.size(),0);
    	permuteDFS(nums,0,visited,out,res);
    	return res;        
    }

    void permuteDFS(vector<int> &nums, int pos, vector<int> &visited, vector<int> &out, vector<vector<int>> &res){

    	if(pos >= nums.size())res.push_back(out);
    	else{
    		for(int i=0 ; i<nums.size() ; i++){
    			if(visited[i]==0){
    				if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0)continue; //排除重复
    				visited[i]=1;
    				out.push_back(nums[i]);
    				permuteDFS(nums, pos+1, visited, out, res);
    				out.pop_back();
    				visited[i]=0;
    			}
    		}
    	}
    }
};