 int maxProfit(vector<int>& prices) {
        int least_so_far = INT_MAX;
        int overall_profit = 0;
        int profit_if_sold_today = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < least_so_far){
                least_so_far = prices[i];
            }
            profit_if_sold_today = prices[i] - least_so_far;
            if(overall_profit < profit_if_sold_today){
                overall_profit = profit_if_sold_today;
            }
        }
        return overall_profit;
    }

