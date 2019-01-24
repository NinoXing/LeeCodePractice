class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int res = nums[0];
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
        		dp1[i] = max(max(dp1[i - 1]*nums[i], dp2[i - 1]*nums[i]), nums[i]);
        		dp2[i] = min(min(dp1[i - 1]*nums[i], dp2[i - 1]*nums[i]), nums[i]);
        		res = max(res, dp1[i]);
        	}
        return res;
    }
};