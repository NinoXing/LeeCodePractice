/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

*/
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char>parentheses;
        for(int i = 0; i < s.size(); ++i){
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        		parentheses.push(s[i]);
        	}
        	else{
        		if(parentheses.empty())return false;
        		if(s[i] == ')' && parentheses.top() != '(')return false;
        		if(s[i] == ']' && parentheses.top() != '[')return false;
        		if(s[i] == '}' && parentheses.top() != '{')return false;
        		parentheses.pop();
        	}
        }
        return parentheses.empty();

    }
};

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {

    	vector<string>res;
    	Dfs(n, n, res, "");
    	return res;
    }

    void Dfs(int left, int right, vector<string> &res, string out){
    	if(left > right)return;
    	if(left == 0 && right == 0)res.push_back(out);
    	else{
    		if(left >0)Dfs(left-1, right, res, out+'(');
    		if(right>0)Dfs(left, right-1, res, out+')');
    	}
    }
};

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<char>parentheses;
        parentheses.push(-1);
        int res=0;
        for(int i=0 ; i<s.size() ; ++i){
        	if(s[i] == '(')parentheses.push(i);
        	else{
        		parentheses.pop();
        		if(!parentheses.empty()){
        			res = max(res, i-parentheses.top());
        		}
        		else{
        			parentheses.push(i);
        		}        	
        	}
    	}
    	return res;

    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(); 
  
        // Create a stack and push -1 as initial index to it. 
        stack<int> stk; 
        stk.push(-1); 

        // Initialize result 
        int result = 0; 

        // Traverse all characters of given string 
        for (int i=0; i<n; i++) 
        { 
            // If opening bracket, push index of it 
            if (s[i] == '(') 
              stk.push(i); 

            else // If closing bracket, i.e.,str[i] = ')' 
            { 
                // Pop the previous opening bracket's index 
                stk.pop(); 

                // Check if this length formed with base of 
                // current valid substring is more than max  
                // so far 
                if (!stk.empty()) 
                    result = max(result, i - stk.top()); 

                // If stack is empty. push current index as  
                // base for next valid substring (if any) 
                else stk.push(i); 
            } 
        } 

        return result;    
    }
};
也有DP做法
DP[i]：以s[i-1]为结尾的longest valid parentheses substring的长度
vector<int>dp(n+1,0)
dp[0]=0;
dp[1]=0;
if(s[i-1]=='(')dp[i]=0;
else if(s[i-1]==')'){
        j=(i-1)-1-dp[i-1];
        if(j<0)dp[i]=0;
        if(s[j]==')')dp[i]=0;
        else{
            dp[i]=dp[i-1]+2+dp[j];
            maxlen = max(dp[i],maxlen)
        }

    }

可以对判断条件合并
if(s[i-1]='(' || j<0 || s[j]==')')dp[i]=0;















