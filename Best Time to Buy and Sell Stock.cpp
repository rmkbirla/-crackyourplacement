class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minp=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]>minp){
                if(profit<prices[i]-minp)
                     profit=prices[i]-minp;
            }else{
                minp=prices[i];
            }
        }
        return profit;
    }
};
