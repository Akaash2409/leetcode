class Solution {
public:
    void solve(int val, int size,int k, int n,vector<int>&curr,vector<vector<int>>& ans){
        if(size<=0){
            if(curr.size()==k){
                ans.push_back(curr);
            }
            return;
        }
        if(val>n) return;

        //include
        curr.push_back(val);
        solve(val+1,size-1,k,n,curr,ans);
        curr.pop_back();
        //not include
        solve(val+1,size,k,n,curr,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1,k,k,n,curr,ans);
        return ans;
    }
};