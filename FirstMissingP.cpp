class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int l = nums.size();
        //int a[l] = {0};
        
        for(int i=0 ; i<nums.size() ; i++){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }

        }
        for(int k=0 ; k<l ; k++){
            if(nums[k]!=k+1){
                return k+1;
            }
        }
        return l+1;
        
    }
};

hashmap做法

