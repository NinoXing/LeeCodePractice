class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        int n = path.size();
        int i=0;
        while(i<n){
        	while(path[i]=='/' && i<n)++i;
        	if(i==n)break;
        	int start = i;
        	while(path[i]!='/' && i<n)++i;
        	int end = i-1;
        	string s = path.substr(start,end-1+start);
        	if(s==".."){
        		if(!res.empty())res.pop_back();
        	}else if(s!='.'){
        		res.push_back(s);
        	}
        }
        if(v.empty())return "/";
        string ans;
        for(int i=0; i<res.size(); i++){
        	ans = ans+'/'+res[i];
        }
        return ans;
    }
};