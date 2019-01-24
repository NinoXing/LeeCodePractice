//
//  Longest Palindromic Substring Longest Palindromic Substring LongestPalindromicSubstring.cpp
//  
//
//  Created by 邢阳 on 2018/11/19.
//

#include <stdio.h>

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int start = 0, maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]) {
                    isPal[i][j] = true;
                    if(j-i+1>maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int start = 0, maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};
        
        for(int i=0; i<n; i++) {
            for(int j=i; j>=0; j--) {
                if((i==j+1 || i==j || isPal[i-1][j+1]) && s[i]==s[j]) {
                    isPal[i][j] = true;
                    if(i-j+1>maxLen) {
                        maxLen = i-j+1;
                        start = j;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};
