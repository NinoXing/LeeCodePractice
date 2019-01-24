//暴力解法
class Solution {
public:
    int trap(vector<int>& height) {
        
        int res=0;
        for(int i=1 ; i<height.size()-1 ; i++){
        	int left=0;
        	int right=0;
        	for(int l=i-1 ; l>=0 ; l--){
        		if(height[l]>height[i]){
        			left = height[l]>left?height[l]:left;
        		}
        	}
        	for(int r=i+1; r<height.size(); r++){
        		if(height[r]>height[i]){
        			right = height[r]>right?height[r]:right;
        		}
        	}
            if(right>0 && left>0){
                int hmin=min(left,right);
                res = res+hmin-height[i]
            }


        }
        return res;
    }
};

//dp 因为不用多次求两边的最大值
class Solution {
public:
    int trap(vector<int>& height) {
        
    	int res=0;
    	int n=height.size();
    	if(n<3)return res;
    	vector<int>dp(n,0);
    	int hmax=0;
    	for(int i=0 ; i<n; i++){
    		dp[i]=hmax;
    		hmax=max(dp[i],height[i]);
    	}
    	hmax=0;
    	for(int i=n-1 ; i>=0 ; i--){
    		dp[i]=min(hmax,dp[i]);
    		hmax=max(hmax,height[i]);
    		if(dp[i]>height[i])res=res+dp[i]-height[i];
    	}
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};