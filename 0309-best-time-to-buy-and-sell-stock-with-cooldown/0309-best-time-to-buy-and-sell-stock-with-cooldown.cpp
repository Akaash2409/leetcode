class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& prices,int idx,int buy){
        if(idx>=prices.size()-1){
            if(buy){
                return 0;
            }
            else{
                if(idx==prices.size()-1){
                    return prices[idx];
                }
                else{
                    return 0;
                }
            }
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            int take = -prices[idx] + solve(dp,prices,idx+1,1-buy);
            int nottake = 0 + solve(dp,prices,idx+1,buy);
            return dp[idx][buy] = max(take,nottake);
        }
        else{
            int take = prices[idx] + solve(dp,prices,idx+2,1+buy);
            int nottake = 0 + solve(dp,prices,idx+1,buy);
            return dp[idx][buy] = max(take,nottake);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(dp,prices,0,1);
    }
};