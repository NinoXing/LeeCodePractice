//The majority element is the element that appears more than ⌊ n/2 ⌋ times.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(cnt == 0){
                major = nums[i];
                cnt++;
            }
            else if(major == nums[i]){
                cnt++;
            }
            else --cnt;
        }
        return major;
    }
};

//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//摩尔投票
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int major = 0;
        int minor = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(major == nums[i])++cnt1;
            else if(minor == nums[i])++cnt2;
            else if(cnt1 == 0) {
                major = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                minor = nums[i];
                cnt2 = 1;
            }
            else --cnt1,--cnt2;
        }
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(major == num)++cnt1;
            else if(minor == num)++cnt2;
        }
        if(cnt1 > nums.size()/3)res.push_back(major);
        if(cnt2 > nums.size()/3)res.push_back(minor);
        return res;
    }
};