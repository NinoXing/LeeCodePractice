class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty())return {};
        vector<string> ans{""};
    	string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    	for(int i=0 ; i<digits.size() ; ++i){

    		vector<string>tmp;

    		int dictnum = digits[i]-'0';
    		string str = dict[dictnum];
    		for(int j=0 ; j<str.size() ; ++j){
    			for(string s : ans)tmp.push_back(s+str[j]);
    		}
    	    ans.assign(tmp.begin(),tmp.end());
    	}  
    	return ans;      
    }
};

//



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            letterCombinationsDFS(digits, dict, level + 1, out+str[i], res);
        }
    }
};