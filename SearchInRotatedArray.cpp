/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

二分法及其衍生

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){

        	int mid = left+(right-left)/2;
        	if(nums[mid]==target)return mid;
        	else if(nums[mid]<nums[right]){
        		if(nums[mid]<target && nums[right]>=target)left = mid + 1;
        		else right = mid - 1;
        	}else{
        		if(nums[left]<=target && nums[mid]>target)right = mid - 1;
        		else left = mid + 1;
        	}
        }
        return -1;   
    }
    
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)return false;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target || nums[left] == target || nums[right] == target)return true;
            else if(nums[mid] < nums[right]){
                if(target > nums[mid] && nums[right] > target) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[mid] > nums[right]){
                if(nums[left] < target && nums[mid] > target)right = mid - 1;
                else left = mid + 1;
            }
            else right--;
        }
        return false;
    }
};