class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> res;
    	vector<int> pos(n,-1);
    	QueenDFS(pos,0,res);
    	return res;        
    }

    void QueenDFS(vector<int> &pos, int row, vector<vector<string>> &res){
    	int n = pos.size();
    	if(row == n){
            vector<string> out(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                out[i][pos[i]] = 'Q';
            }
    			res.push_back(out);
    		}

    	else{
    		for(int j=0; j<n; j++){
    			if(IsValid(j,row,pos)){
    				pos[row]=j;
    				QueenDFS(pos,row+1,res);
    				pos[row]=-1;
    			}
    		}
    	}
    }

    bool IsValid(int j, int row, vector<int> &pos){
    	for(int m=0; m<row; m++){
    		if(j==pos[m] || abs(m-row)==abs(pos[m]-j)){
    			return false;
    		}
    	}
    	return true;
    }
};