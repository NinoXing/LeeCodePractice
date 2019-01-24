/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = n - 1; i >= 0; i--){
        	for(int j = i; j < n; j++){
        		if((i + 1 >= j-1 || dp[i+1][j-1]) && s[i]==s[j])
        			dp[i][j]=true;
        	}
        }
        partitionDFS(0,s,dp,out,res);
        return res;
    }
    void partitionDFS(int start, string s, vector<vector<bool>> dp, vector<string> &out, vector<vector<string>> &res){
    	if(start == s.size()){
    		res.push_back(out);
    		return;
    	}
    	for(int i = start; i<s.size(); i++){
    		if(dp[start][i]){
    			int len = i-start+1;
    			out.push_back(s.substr(start,len));
    			partitionDFS(i+1, s, dp, out, res);
    			out.pop_back();
    		}
    	}
    }

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

using dynamic programming
dp[i]为s[0]到s[i-1](s[0:i-1])最小切割数
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n<=1)return 0;
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for(int i = n - 1; i >= 0; i--){
        	for(int j = i; j < n; j++){
        		if((i + 1 >= j - 1 || isPal[i+1][j-1]) && s[i]==s[j])
        			isPal[i][j]=true;
        	}
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=-1;
        for(int i=1; i<=n; i++){
        	for(int j=i-1; j>=0; j--){
        		if(isPal[j][i-1]){
        			dp[i]=min(dp[i],dp[j]+1);
        		}
        	}
        }
        return dp[n];
    }
};

//125. Valid Palindrome
class Solution {
    bool isLetter(char &s){
        if((s >= 'a' && s <= 'z')||(s >= 'A' && s <= 'Z')||(s >= '0' && s <= '9')) return true;
        else
            return false;
    }
    
public:
    bool isPalindrome(string s) {
        if(s.empty())return true;
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(!isLetter(s[left]))left++;
            else if(!isLetter(s[right]))right--;
            else if((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32)return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};