class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        
        for(int& num : nums){
            ++counter[num];
        }
        
        vector<int> ans;
        int n = nums.size();
        
        for(auto it = counter.begin(); it != counter.end(); ++it){
            if(it->second > n/3){
                ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};