/*
dp[i]=1 能reach到

dp[i]=1:if(dp[k]=1 && nums[k]>=i-k)
dp[0]=1
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int n=nums.size();
    	vector<int>dp(n,0);
    	dp[0]=1;
    	for(int i=1; i<n; i++){
    		for(int j=i-1; j>=0; j--){
    			if(dp[j]==1 && nums[j]>=i-j){
    				dp[i]=1;
    				break;
    			}
    		}
    	}
    	if(dp[n-1]!=0)return true;
    	else
    		return false;
        
    }
};


/*
贪心算法
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};

//Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return -1; // May not need this表示无法达到末尾
        }
        return res;
    }
};