class Solution {
public:
    using int3 = array<int, 3>;
    vector<int3> jobs; 
    vector<int> dp;
    int n;
    vector<int> next;

   void binary_search() {
        for (int i = 0; i < n; i++) {
            
            next[i] = upper_bound(jobs.begin()+i, jobs.end(),
                array<int, 3>{jobs[i][1], 0, 0}) - jobs.begin();
        
        }
    }

    int dfs(int i) {
        if (i == n ) return 0;
        if (dp[i]!= -1) return dp[i];

      
        int profit_w_i = jobs[i][2] + dfs(next[i]);

     
        int profit_n_i = dfs(i+1);

      
        return dp[i] = max(profit_w_i, profit_n_i);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        n = startTime.size();
        jobs.assign(n, {-1, -1, -1});
        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());
      
        next.assign(n, -1);

        dp.assign(n+1, -1);
        binary_search();
        return dfs(0);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();