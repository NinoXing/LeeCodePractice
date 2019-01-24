class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) nums[i + 1] = nums[i] + 1;
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
        for (int num : nums) res += num;
        return res;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int res = 1, pre = 1, cnt = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                if (cnt > 0) {
                    res += cnt * (cnt + 1) / 2;
                    if (cnt >= pre) res += cnt - pre + 1;
                    cnt = 0;
                    pre = 1;
                }
                pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1;
                res += pre;
            } else {
                ++cnt;
            }
        }     
        if (cnt > 0) {
            res += cnt * (cnt + 1) / 2;
            if (cnt >= pre) res += cnt - pre + 1;
        }
        return res;
    }
};