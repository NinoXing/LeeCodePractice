/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.*/

/*
it is easy if the price is positive
Input: [7,1,5,3,6,4]
Output: 5
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int res = 0;
        for(int price : prices){
            minprice = min(price, minprice);
            res = max(price - minprice, res);
        }
        return res;
    }
};

//But if the price can be negitive, it is a question about maxsum subarry problem.
//the best way is Kadane's Algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curPrice = 0; //we assume the maxprice should be positive or 0
        int maxPrice = INT_MIN;
        for(int i = 1; i < prices.size(); ++i){
        	curPrice = max(0, curPrice + prices[i] - prices[i - 1]);
        	maxPrice = max(curPrice, maxPrice);
        }
        return maxPrice;
    }
};

//Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() < 2)return 0;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
        	res = (prices[i] > prices[i - 1]) ? res + prices[i] - prices[i - 1] : res;
        }
        return res;
    }
};

//Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() < 2)return 0;
    	vector<vector<int>> local(prices.size(),vector<int>(3, 0));
    	vector<vector<int>> global(prices.size(),vector<int>(3, 0));

    	for(int i = 1; i < prices.size(); ++i){
    		for(int j = 1; j < 3; ++j){
    			local[i][j] = max(global[i - 1][j - 1] + prices[i] - prices[i - 1], local[i - 1][j] + prices[i] - prices[i - 1]);
    			global[i][j] = max(global[i - 1][j], local[i][j]);
    		}
    	}
    	return global[prices.size() - 1][2];
    }
};

//Best Time to Buy and Sell Stock IV
//genralize QIII from 2 to k
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	if(prices.size() < 2)return 0;
    	if(k >= prices.size()) return easysolve(prices);
    	vector<vector<int>> local(prices.size(),vector<int>(k + 1, 0));
    	vector<vector<int>> global(prices.size(),vector<int>(k + 1, 0));

    	for(int i = 1; i < prices.size(); ++i){
    		for(int j = 1; j < k + 1; ++j){
    			local[i][j] = max(global[i - 1][j - 1] + prices[i] - prices[i - 1], local[i - 1][j] + prices[i] - prices[i - 1]);
    			global[i][j] = max(global[i - 1][j], local[i][j]);
    		}
    	}
    	return global[prices.size() - 1][k];        
    }
    int easysolve(vector<int>& prices) {
    	if(prices.size() < 2)return 0;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
        	res = (prices[i] > prices[i - 1]) ? res + prices[i] - prices[i - 1] : res;
        }
        return res;
    }    
};

//Best Time to Buy and Sell Stock with Cooldown





















