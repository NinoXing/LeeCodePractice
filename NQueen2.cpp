class Solution {
public:
    int totalNQueens(int n) {
    	int res=0;
    	vector<int> pos(n,-1);
    	QueenDFS(pos,0,res);
    	return res;
    }

    void QueenDFS(vector<int> &pos, int row, int &res){
    	int n = pos.size();
    	if(row == n)res=res+1;
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