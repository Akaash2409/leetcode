class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<1){
            return {-1,-1}; 
        }
        if(n==1){
            if(nums[0]==target){
                return {0,0};
            }else{
                return {-1,-1};
            }
        }
        int start=0;
        int end=n-1;
        int mid;
        int found=-1;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }else if(nums[mid]==target){
                found=1;
                break;
            }else{
                start=mid+1;
            }
        }   
        if(found==-1){
            return {-1,-1};
        }

        // now expand in both directions
        int rightindex=mid;
        int leftindex=mid;
        while(rightindex<n-1&&nums[rightindex+1]==target){
            rightindex++;
        }
        while(leftindex>0&&nums[leftindex-1]==target){
            leftindex--;
        }
        return {leftindex,rightindex};
    }
};