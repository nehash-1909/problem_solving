/****************************************************************************************************************
2. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
****************************************************************************************************************/

//Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_stock = prices[0]; // 7

        for(int i=1;i<prices.size();i++)
        {
            if(buy_stock>prices[i])
            {
                buy_stock = prices[i];   
            }
            if(max_profit < prices[i]-buy_stock)
            {
                max_profit = prices[i]-buy_stock;
            }
        }
        return max_profit;
        
    }
};
