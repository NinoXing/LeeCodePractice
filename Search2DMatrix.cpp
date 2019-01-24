class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;
        if(target<matrix[0][0] || target>matrix.back().back())return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left=0, right=m-1;
        while(left<=right){
        	int mid = (left+right)/2;
        	if(matrix[mid][0]==target)return true;
        	else if(matrix[mid][0]<target)left = mid+1;
        	else right = mid-1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size()-1;
        while(left<=right){
        	int mid=(left+right)/2;
        	if(matrix[tmp][mid]==target)return true;
        	else if(matrix[tmp][mid]<target)left = mid + 1;
        	else right= mid - 1;
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};


//240. Search a 2D Matrix II
//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;
        if(target > matrix.back().back() || target < matrix[0][0])return false;
        int x = matrix.size() - 1, y = 0;
        while(true){
            if(target > matrix[x][y])++y;
            else if(target < matrix[x][y])--x;
            else return true;
            if(x < 0 || y > matrix[0].size())return false;
        } 
        return false;      
    }
};