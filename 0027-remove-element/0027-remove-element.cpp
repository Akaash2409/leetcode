class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=-1;
        int flag=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=val){
                flag=1;
                i++;
                nums[i]=nums[j];
            }
        }
        if(flag==0){
            return 0;
        }
        return i+1;
    }
};