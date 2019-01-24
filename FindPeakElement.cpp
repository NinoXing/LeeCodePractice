class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int pre = INT_MIN;
        nums.push_back(INT_MIN);
        for(int i = 0; i < n; ++i){
        	if(nums[i] > pre && nums[i] > nums[i + 1])return i;
        	else if(nums[i] < pre && nums[i] < nums[i + 1]) return i;
        	else
        		pre = nums[i];
        }
        return 0;
    }
};