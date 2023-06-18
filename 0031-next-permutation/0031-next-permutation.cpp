class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        
        for(int i = n-2; i >= 0; --i){
            if(nums[i] < nums[i+1]){
                int minidx = i+1;
                for(int j = i+1; j < n; ++j){
                    if(nums[j] > nums[i]){
                        minidx = (nums[j] < nums[minidx]) ? j : minidx;
                    }
                }
                
                
                swap(nums[i], nums[minidx]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        
        sort(nums.begin(), nums.end());
    }
};