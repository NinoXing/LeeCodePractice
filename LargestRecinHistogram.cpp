class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)return 0;
        heights.push_back(0);
        stack<int> s;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
        	if(s.empty() || heights[s.top()] < heights[i]){
        		s.push(i);
        	}
        	else{
        		int tmp = s.top();
        		s.pop();
        		int current = heights[tmp]*(s.empty()? i : i-s.top()-1);
        		res = max(res , current);
        		i--;
        	}
        }
        return res;
    }
};


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.size() == 0 || matrix[0].size() == 0)return 0;
        vector<vector<int>> heights(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i = 0; i < matrix[0].size(); i++){
        	heights[0][i] = (matrix[0][i] == '0'? 0:1);
        }
        for(int i = 1; i < matrix.size(); i++){
        	for(int j = 0; j < matrix[0].size(); j++){
        		heights[i][j] = (matrix[i][j] == '0'?0:heights[i-1][j]+1);
        	}
        }
        int res = largestRectangleArea(heights,0);
        return res;
    }

    int largestRectangleArea(vector<vector<int>>& heights,int res) {
        for(int j = 0; j < heights.size(); j++){
        	heights[j].push_back(0);
        	stack<int> s;
	        for(int i = 0; i < heights[j].size(); i++){
	        	if(s.empty() || heights[j][s.top()] < heights[j][i]){
	        		s.push(i);
	        	}
	        	else{
	        		int tmp = s.top();
	        		s.pop();
	        		int current = heights[j][tmp]*(s.empty()? i : i-s.top()-1);
	        		res = max(res , current);
	        		i--;
	        	}
	        }
    	}
        return res;
    }

};