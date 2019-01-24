#include <vector>
using namespace std;


//house robber 1
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        int n=nums.size();
        vector<int>ansdp1(n);
        ansdp1[0]=nums[0];
        ansdp1[1]=max(nums[1],nums[0]);

        for(int i=2 ; i<n ; i++){
            ansdp1[i]=max(ansdp1[i-1],ansdp1[i-2]+nums[i]);
        }       
        

        return ansdp1[n-1];
    }
};


//house robber2
//去掉头或者去掉尾
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        if (right - left <= 1) return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < right; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};
//house robber3
//其实是涉及到dfs思想和dp思想的递归算法
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }
    int helper(TreeNode* node, int& l, int& r) {
        if (!node) return 0; //递归的结束
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};

