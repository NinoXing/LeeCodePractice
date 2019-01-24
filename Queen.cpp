class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<srting>> res;
        vector<int> pos(n,-1);
        QueenDFS(pos, 0, res);
        return res;
    }
    
    void QueenDFS(vector<int> &pos, int row, vector<vector<string>> &res){
        int n = pos.size();
        if(row == n){
            for(int i=0; i<n; i++){
                vector<string> tmp(n,string(n, '.');
                tmp[pos[i]]='Q';
                res.push_back(tmp);
                                   
                                   }
                                   }
                                   else{
                                       for(int j=0; j<n; j++){
                                           if(IsValid(j,row,pos)){
                                               pos[row]=j;
                                               QueenDFS(pos, row+1, res);
                                               pos[row]=-1;
                                           }
                                       }
                                   }
                                   }
                                   
                                   bool IsValid(int j, int row, vector<int> pos){
                                       for(int i=0; i<row; i++){
                                           if(j==pos[i] || abs(pos[i]-j)==abs(i-row){
                                               return false;
                                           }
                                              }
                                              return true;
                                              }
                                              };
