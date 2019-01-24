
//一般做法
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    	if (strs.empty()) return "";
        string ans="";
        int n=strs.size();
        int l=strs[0].size();
        for(int i=0 ; i<l ; i++){
        	for(int j=0 ; j<n ; j++){
        		if(i>=strs[j].size() || strs[j][i]!=strs[0][i]){
        			return ans;
        		}
        	}
        	ans.push_back(strs[0][i]);
        }

        return ans;
    }
};


//先sort，再判断只需判断首尾
#include<algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
