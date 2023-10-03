class Solution {
public:
    void backtrack(int k, int n, vector<int>& cur, vector<vector<int>>& ans){
        if(cur.size() == k){
            if(accumulate(cur.begin(), cur.end(), 0) == n){
                ans.push_back(cur);
            }
        }else{
            for(int i = (cur.empty() ? 1 : cur.back()+1); i <= 9; ++i){
                cur.push_back(i);
                
                backtrack(k, n, cur, ans);
                
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> ans;
        
        backtrack(k, n, cur, ans);
        
        return ans;
    }
};