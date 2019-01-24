#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

    	int n = triangle.size();
    	vector< vector<int> >dp(n,vector<int>(n));
    	int re = INT_MAX;

    	if (triangle.empty())return 0;

    	dp[0][0] = triangle[0][0];

    	for(int i=1 ; i<n ; i++){

    		for (int j=0 ; j<i+1 ; j++ ){

    			if(j==0){
    				dp[i][j]=dp[i-1][j]+triangle[i][j];
    			}
    			else if(j==i){
    				dp[i][j]=dp[i-1][j-1]+triangle[i][j];
    			}
    			else{
    				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
    			}
    		}
    	}

    	for (int k=1; k<n ;k++){
    		re = dp[n-1][k]<re?dp[n-1][k]:re;
    	}
        
        return re;
    }
};