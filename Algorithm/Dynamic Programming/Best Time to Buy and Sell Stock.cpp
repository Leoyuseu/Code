// // Best Time to Buy and Sell Stock 1
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one 
// and sell one share of the stock), design an algorithm to find the maximum profit.

//similar to maximum sum subarray
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<int> profit;
        for(int i=1;i<prices.size();++i){
            profit.push_back(prices[i]-prices[i-1]);
        }
        int maxfit=profit[0];
        int start=profit[0];
        for(int i=1;i<profit.size();++i){
            start=max(profit[i],profit[i]+start);
            maxfit=max(start,maxfit);
        }
        return maxfit>0?maxfit:0;
    }   
};

//more clear solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int profit = 0;
        int localProfit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            localProfit = max(localProfit+prices[i+1]-prices[i],0);
            profit = max(profit, localProfit);
        }
        return profit;
    }
};

//Best Time to Buy and Sell Stock II
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
// transactions at the same time (ie, you must sell the stock before you buy again).


 // suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt. And suppose another one is "a <= b >= b' <= c <= d", 
 // the profit is not difficult to be figured out as "(b - a) + (d - b')".
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int maxfit=0;
        for(int i = 0; i < prices.size() - 1; i++){
            maxfit += max(prices[i + 1] - prices[i], 0);
            //if(prices[i]-prices[i-1]>0) max_pro+=prices[i]-prices[i-1];
        }
        return maxfit;
    }
};