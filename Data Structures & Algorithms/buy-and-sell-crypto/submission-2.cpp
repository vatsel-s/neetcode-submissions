class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; 
        int min_cost = prices[0]; 
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - min_cost > max_profit)
            {
                max_profit = prices[i] - min_cost; 
            }
            if(prices[i] < min_cost)
            {
                min_cost = prices[i]; 
            }
        }
        return max_profit; 
    }
};
