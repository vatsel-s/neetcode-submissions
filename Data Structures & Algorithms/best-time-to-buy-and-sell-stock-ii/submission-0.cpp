class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //any number of transactions but you can at most have one share of stock
        //we can essentially have 2 DP arrays
        //Jesus Christ the acceptance rate is high
        vector<int> profit_sold(prices.size(), -INT_MAX); 
        vector<int> profit_bought(prices.size(), -INT_MAX); 
        //now what's the actual recursive step, we can either choose to buy or to sell
        //let's put in the base cases for each possibility here
        profit_sold[0] = 0; //start off with us not having anything sold
        profit_bought[0] = -prices[0]; 
        cout << profit_bought[0] << " " << profit_sold[0] << endl; 
        for(int i = 1; i < prices.size(); i++)
        {
            //best version of profit_bought is going to be us buying the stock from the previous profit sold
            //or we just keep the previous profit
            profit_bought[i] = max(profit_sold[i-1] - prices[i], profit_bought[i - 1]); 
            //for profit sold, we either sell from the last one or keep the previous value
            profit_sold[i] = max(profit_bought[i - 1] + prices[i], profit_sold[i - 1]); 
            cout << profit_bought[i] << " " << profit_sold[i] << endl; 
        }
        return profit_sold[prices.size() - 1]; 
    }
};