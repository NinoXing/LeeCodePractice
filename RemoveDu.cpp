#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

//注意原题是pass by reference
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return j + 1;
    }
};

//80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int pre = 0;
        int cur = 1;
        int count = 1;
        int len = nums.size();
        while(cur < n){
            if(nums[pre] == nums[cur] && count == 0 ) ++cur;
            else{
                if(nums[pre] == nums[cur])--count;
                else count = 1;
                nums[++pre] = nums[cur++]
            }
        }
        return pre + 1;
    }
};