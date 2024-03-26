class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<n){
            if(arr[i]==i+1){
                i++;
            }
            else if (arr[i]>=1 && arr[i]<=n){
                if(arr[i]==arr[arr[i]-1]){
                    i++;
                }
                else{
                    swap(arr[i],arr[arr[i]-1]);
                }
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if (arr[i]!=i+1){
                return i+1;
            }
        }
    return n+1;
    }
};