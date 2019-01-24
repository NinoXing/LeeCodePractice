class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); ++i){
        	if(m.find(target - numbers[i]) == m.end())m[numbers[i]] = i;
        	else{
        		res.push_back(m[target - numbers[i]] + 1);
        		res.push_back(i + 1);
        		return res;
        	}
        }
    }
};