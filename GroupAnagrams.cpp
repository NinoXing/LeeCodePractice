#include<string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string,vector<string>> map;
    	vector<vector<string>> res;
    	for(int i=0; i<strs.size(); i++){
    		string tmp = strs[i];
    		sort(tmp.begin(),tmp.end());
    		map[tmp].push_back(strs[i]);
    	}
    	for(auto a : map){
    		res.push_back(a.second);
    	}
    	return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) ++cnt[c - 'a'];
            for (int d : cnt) t += to_string(d) + "/";
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};