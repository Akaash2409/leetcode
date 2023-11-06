//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        vector<vector<int>>dp(S.length()+1,vector<int>(S.length()+1,0));
int n=S.length();
int w=-1,e=-1,ans=0;
for(int diff=0;diff<n;diff++)
{
    for(int i=0,j=i+diff;j<n;i++,j++)
    {
        if(diff==0)
        {
            dp[i][j]=1;
            if(ans<dp[i][j])
            {
                ans=dp[i][j];
                w=i;e=j;
            }
        }
        else if(diff==1)
        {
            if(S[i]==S[j])
            {
                dp[i][j]=2;
            }
            else{
                dp[i][j]=0;
            }
            if(ans<dp[i][j])
            {
                ans=dp[i][j];
                w=i;e=j;
            }
        }
        else{
            if(S[i]==S[j] && dp[i+1][j-1]!=0)
            {
                dp[i][j]=dp[i+1][j-1]+2;
                
            }
            else{
                dp[i][j]=0;
            }
            if(ans<dp[i][j])
            {
                ans=dp[i][j];
                w=i;e=j;
            }
        }
    }
}
string st="";
while(w<=e)
{
    st=st+S[w];
    w++;
}
return st;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends