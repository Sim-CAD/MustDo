 //Problem Name: Best Time to Buy and Sell Stock - LeetCode
 //Source : GeeksForGeeks
 /****************************************/
int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        
        if(prices.size() < 2)
            return 0;
        int max_profit = INT_MIN;
        
        int cur_profit  = prices[buy] - prices[sell];
        
        while(sell < prices.size()){
            if(prices[buy] > prices[sell]){
                buy = sell;
            }
            
            cur_profit = prices[sell] - prices[buy];
            
            max_profit = max(max_profit, cur_profit);
            sell++;
            
        }
        return max_profit;
    }