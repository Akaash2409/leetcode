class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto it : magazine){
            mp[it]++;
        }
        for(char c : ransomNote){
            if(mp.find(c)!=mp.end() && mp[c]>0)
                mp[c]--;
            else
                return false;
        }
        return true;
    }
};