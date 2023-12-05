//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n)
    {
        // code here
        int ans=0;
        int prev1=0;
        int prev2=1;
        
        if(n==1)
        return 1;
        else
        {
            n--;
            while(n)
            {
                int current=(prev2+prev1)%1000000007;
                ans=current;
                n--;
                prev1=prev2;
                prev2=current;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends