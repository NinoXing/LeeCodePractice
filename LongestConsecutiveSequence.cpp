/*
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> map;
        for(int num : nums){
            if(!map.count(num)){
                int left = map.count(num-1)?map[num-1]:0;
                int right = map.count(num+1)?map[num+1]:0;
                int sum = left + right + 1;
                res = max(res, sum);
                map[num] = sum;
                map[num-left] = sum;
                map[num+right] = sum;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for(int num : nums){
            if(!set.count(num))continue;
            set.erase(num);
            int left = num - 1;
            int right = num + 1;
            while(set.count(left))set.erase(left--);
            while(set.count(right))set.erase(right++);
            res = max(res, right - left - 1);
        }
        return res;
    }
};