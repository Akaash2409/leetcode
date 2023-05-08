class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<=2){
            return ans;
        }

        for(int i=0;i<n-2;i++){

            // don't repeat a certain value in i
            // to avoid repetitions
            if(i==0||nums[i]>nums[i-1]){

                // 2 pointers => front,back
                int j=i+1;
                int k=n-1;

                while(j<k){
                    int val=nums[j]+nums[k]+nums[i];
                    if(val==0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                    }

                    if(val<0){
                        int j_val=nums[j];
                        while(nums[j]==j_val&&j<k){
                            j++;
                        }
                    }else{
                        int k_val=nums[k];
                        while(nums[k]==k_val&&j<k){
                            k--;
                        }
                    }
                }

            }

        }
        return ans;
    }
};