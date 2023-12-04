//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long curr_sum = arr[0];
        long long overall_sum = arr[0];
        
        for(int i=1; i<n; i++){
            if(curr_sum >= 0)
            {
                curr_sum += arr[i];
            }
            else
            {
                curr_sum = arr[i];
            }
            
            if(curr_sum > overall_sum){
                overall_sum = curr_sum;
            }
        }
        
        return overall_sum;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends