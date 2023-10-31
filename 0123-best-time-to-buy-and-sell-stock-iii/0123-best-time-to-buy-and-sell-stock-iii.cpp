class Solution {
public:
    
    int solve(int idx,int opt,vector<int>& prices,int limit,vector<vector<vector<int>>> &dp){
        if(prices.size() == idx)
            return 0;
        if(limit == 0)
            return 0;
        if(dp[idx][opt][limit] != -1)
            return dp[idx][opt][limit];
        int profit = 0;
        if(opt == 0)
            profit = max(-prices[idx]+solve(idx+1,1,prices,limit,dp), 
                                      solve(idx+1,0,prices,limit,dp));
        else
            profit = max(prices[idx]+solve(idx+1,0,prices,limit-1,dp),                                                                  solve(idx+1,1,prices,limit,dp));
        return dp[idx][opt][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,prices,2,dp);
    }
};