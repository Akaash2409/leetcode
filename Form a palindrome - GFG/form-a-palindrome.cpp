//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i, int j, string& str1, string& str2, vector<vector<int>>&dp) {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i-1]==str2[j-1]) return 1 + solve(i-1,j-1,str1,str2,dp);
        
        return dp[i][j] = max(solve(i-1,j,str1,str2,dp),solve(i,j-1,str1,str2,dp));
    }
    int lps(string& str) {
        string temp = str;
        reverse(temp.begin(),temp.end());
        int n = str.size();
        int m = temp.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,str,temp,dp);
       
    }
    int countMin(string str){
      return str.size() - lps(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends