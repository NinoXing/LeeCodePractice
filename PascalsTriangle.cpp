#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        //vector< vector<int> >ans(numRows,vector<int>(numRows,0));
        vector<vector<int>>ans;
        if(numRows==0)return ans;

        for(int i=0 ; i<numRows ; i++){
            vector<int>row_i;
            for (int j=0 ; j<i+1 ; j++ ){

                if(j==0){
                    row_i.push_back(1);
                }
                else if(j==i){
                    row_i.push_back(1);
                }
                else{
                    row_i.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(row_i);
        }
        
        return ans;
    }
};