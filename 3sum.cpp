#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    	vector<vector<int>>ans;
    	sort(nums.begin(),nums.end());
    	if(nums.empty() || nums.front()>0 || nums.back()<0) return {};
    	for (int k=0 ; k<nums.size() ; ++k){
    		if(nums[k]>0) break;
    		if(k>0 & nums[k]==nums[k-1]) continue;
    		int target = 0-nums[k];
    		int i=k+1;
    		int j=nums.size()-1;
    		while(i<j){
    			if(nums[i]+nums[j]==target){
    				ans.push_back({nums[k],nums[i],nums[j]});
    				while(nums[i]==nums[i+1])++i;
    				while(nums[j]==nums[j-1])--j;
    				++i;
    				--j;
    			}else if(nums[i]+nums[j]<target)++i;
    			else
    				--j;
    		}

    	}
    	return ans;
    }
};


//3 sum closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

    	int ans = nums[0]+nums[1]+nums[2];
    	int diff = abs(ans-target);
    	sort(nums.begin(),nums.end());
    	for (int k=0 ; k<nums.size()-2 ; ++k){
    		int i=k+1;
    		int j=nums.size()-1;
    		while(i<j){
    			int newdiff=abs(nums[k]+nums[i]+nums[j]-target);
    			if(diff>newdiff){
    				diff = newdiff;
    				ans = nums[k]+nums[i]+nums[j];
    			}

    			if(nums[i]+nums[j]+nums[k]<target)++i;
    			else
    				--j;
    		}

    	}
    	return ans;
    }
};





