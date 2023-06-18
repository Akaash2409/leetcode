class Solution {
public:
    int findMinIdx(vector<int>& nums){
        int l = 0, r = nums.size()-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums.back()){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        
        return l;
    };
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int minIdx = findMinIdx(nums);
        if(nums[minIdx] == target) return minIdx;
        
        
        int l, r;
        if(nums[n-1] >= target){
            l = minIdx + 1;
            r = n-1;
        }else{
            l = 0;
            r = minIdx-1;
        }
        
        while(l <= r){
            int mid = l + (r-l)/2;
                        
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return -1;
    }
};