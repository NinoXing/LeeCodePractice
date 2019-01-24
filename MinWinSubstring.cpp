class Solution {
public:
    string minWindow(string s, string t) {
    	string res = "";
    	unordered_map<char,int> letterCnt;
    	for(char c : t) letterCnt[c]++;
        int left = 0;
    	int cnt = 0;
    	int minLen=INT_MAX;
    	for(int i = 0 ; i < s.size() ; ++i){
    		if(letterCnt[s[i]]-1>=0) ++cnt;
    		while(cnt == t.size()){
    			if(minLen > i - left +1 ){
    				minLen = i - left + 1;
    				res = s.substr(left, minLen);
    			}
    			if(letterCnt[s[left]] + 1  > 0) --cnt;
    			++left;
    		}
    	}
    	return res;
    }
};