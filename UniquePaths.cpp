/*class Solution {
public:
    int uniquePaths(int m, int n) {

        //int a[m][n]={0};
        int res=0;
        uniquePathsDFS(m,n,0,0,res)
        return res;   
    }

    void uniquePathsDFS(int m, int n, int row, int col, int &res){
    	if(row==m-1 && col==n-1)res=res+1;
    	else{
    		uniquePathsDFS(m,n,row+1,col,res);
    		uniquePathsDFS(m,n,row,col+1,res);
    	}
    }
};*/

class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int>> dp(n,vector<int>(m,0));
    	for(int i=0; i<m; i++){
    		dp[0][i]=1;
    	}
    	for(int j=0; j<n; j++){
    		dp[j][0]=1;
    	}
    	for(int i=1; i<m; i++){
    		for(int j=1; j<n; j++){
    			dp[j][i]=dp[j-1][i]+dp[j][i-1];
    		}
    	}
    	return dp[n-1][m-1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1)return 0;
    	int m=obstacleGrid[0].size();
    	int n=obstacleGrid.size();
    	vector<vector<int>> dp(n,vector<int>(m,0));

    	for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			if(obstacleGrid[j][i]==1) dp[j][i]=0;
    			else if(j==0 && i==0) dp[j][i]=1;
    			else if(j>0 && i==0) dp[j][i]=dp[j-1][i];
    			else if(j==0 && i>0) dp[j][i]=dp[j][i-1];
    			else dp[j][i]=dp[j-1][i]+dp[j][i-1];
    		}
    	}
    	return dp[n-1][m-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid[0].size();
    	int n=grid.size();
    	vector<vector<int>> dp(n,vector<int>(m,0));

    	for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			//if(obstacleGrid[j][i]==1) dp[j][i]=0;
    			if(j==0 && i==0) dp[j][i]=grid[0][0];
    			else if(j>0 && i==0) dp[j][i]=dp[j-1][i]+grid[j][i];
    			else if(j==0 && i>0) dp[j][i]=dp[j][i-1]+grid[j][i];
    			else dp[j][i]=min(dp[j-1][i]+grid[j][i],dp[j][i-1]+grid[j][i]);
    		}
    	}
    	return dp[n-1][m-1];
    }
};