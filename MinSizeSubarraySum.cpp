class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0;
        int res = nums.size() + 1;
        while(right < nums.size()){
        	while(sum < s && right < nums.size()){
        		sum += nums[right++];
        	}
        	while(sum >= s){
        		res = min(res, right - left);
        		sum -= nums[left++];
        	}
        }
        return res == nums.size() + 1 ? 0 : res; 
    }
};