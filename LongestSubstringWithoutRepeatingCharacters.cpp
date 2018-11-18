//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  
//
//  Created by 邢阳 on 2018/11/18.
//

#include <stdio.h>
#include <string>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};
