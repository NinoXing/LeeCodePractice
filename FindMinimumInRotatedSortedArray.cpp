//Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        if (num[left] > num[right]) {
            while (left != (right - 1)) {
                int mid = (left + right) / 2;
                if (num[left] < num[mid]) left = mid;
                else right = mid;
            }
            return min(num[left], num[right]);
        }
        return num[0];
    }
};

//Find Minimum in Rotated Sorted Array II
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};
//When num[mid] == num[hi], we couldn't sure the position of minimum in mid's left or right
//so just let upper bound reduce one.