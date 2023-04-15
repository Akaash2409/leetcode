class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        vector<int> finals;
        
        int i=0;
        int j=nums.size()-1;
        //map<int, int> mp;
        vector<int> vec2;
            for(int i=0;i<nums.size();i++)
            {
                vec2={nums[i], i};
                vec.push_back(vec2);
            }
        sort(vec.begin(), vec.end());
        while(i<j)
        {
            if((vec[i][0]+vec[j][0])==target)
            {
                finals.push_back(vec[i][1]);
                finals.push_back(vec[j][1]);
                return finals;
            }
            else if((vec[i][0]+vec[j][0])>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return finals;
    }
};