class FoodRatings {
    using item=pair<int, string>;//(rating, food), (rating, cuisine)
    unordered_map<string, set<item>> Rated;
    unordered_map<string, item> mp;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        int n=foods.size();
        for(int i=0; i<n; i++){
            string food=foods[i], cuisine=cuisines[i];
            int rating=ratings[i];
            mp[food]={-rating, cuisine};//take minus
            Rated[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = mp[food].second;
        int i = mp[food].first;
        Rated[cuisine].erase({i, food});
        Rated[cuisine].insert({-newRating, food});
        mp[food]={-newRating, cuisine};
    }
    
    string highestRated(string cuisine) {
        return Rated[cuisine].begin()->second;
    }

};


 auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();