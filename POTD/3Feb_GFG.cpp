//Stock Buy and Sell – Max one Transaction Allowed

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int mini=prices[0];
        int profit;
        int maxProfit =0;
        for(int i=1;i<prices.size();i++){
            if(mini>prices[i]){
                mini = min(mini,prices[i]) ;
            }
            else{
                profit = prices[i]-mini;
                maxProfit = max(maxProfit,profit);
            }
            
            
        }
        return maxProfit;
    }
};
