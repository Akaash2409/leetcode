//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
 
long long maxProduct(vector<int> arr, int n) {
    
    
    long long ans=INT_MIN;
    long long prefixSum=1;
    long long suffixSum=1;
    
    for(long long i=0; i<n; i++){
        
        if(prefixSum==0) prefixSum=1;
        if(suffixSum==0) suffixSum=1;
        
        prefixSum = prefixSum * arr[i];
        suffixSum = suffixSum * arr[n-i-1];
        ans=max(ans,max(prefixSum, suffixSum));
        
    }
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends