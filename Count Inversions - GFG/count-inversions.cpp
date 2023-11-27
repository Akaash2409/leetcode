//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], long long l, long long m, long long r) {
        long long left = l, right = m + 1;
        vector<long long> temp;
        long long cnt = 0;
        while(left <= m && right <= r) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                cnt += (m - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= m) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long i=0; i<temp.size(); i++) {
            arr[l+i] = temp[i];
        }
        
        return cnt;
    }
    
    
    long long mergeSort(long long arr[], long long left, long long right) {
        long long cnt = 0;
        if(left < right) {
            long long mid = left + (right-left)/2;
            cnt += mergeSort(arr, left, mid);
            cnt += mergeSort(arr, mid+1, right);
            cnt += merge(arr, left, mid, right);
        }
        return cnt;
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long cnt = 0;
        cnt = mergeSort(arr, 0, N-1);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends