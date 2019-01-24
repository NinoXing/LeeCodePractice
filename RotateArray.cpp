class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	if(nums.empty() || (k %= nums.size()) == 0)return;
    	int n = nums.size();
    	for(int i = 0; i < n - k; ++i){
    		nums.push_back(nums[0]);
    		nums.erase(nums.begin());
    	}
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	if(nums.empty() || (k %= nums.size()) == 0)return;
    	int n = nums.size();
    	reverse(nums.begin(), nums.begin() + n - k);
    	reverse(nums.begin() + n - k, nums.end());
    	reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};