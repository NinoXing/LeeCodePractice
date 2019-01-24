#include <unordered_map>

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

 		vector<int>ans;
 		vector<int>ans2;
    	if(s.empty() || words.empty())return ans;
    	int subl = words[0].size();

    	unordered_map<string,int>m;

    	for(int i=0 ; i<words.size() ; ++i){
    		if(words[i].size()!=subl)return ans;
    		m[words[i]] = i;
    	}
        int j = 0;
    	while(j<=s.size()-subl){
    		string tmp = s.substr(j,subl);
    		if(m.find(tmp)!=m.end()){
    			ans.push_back(j);
    			j = j+subl;
    		}
    		else
    			j = j+1;

    	}

    	return ans;
        
    }
};