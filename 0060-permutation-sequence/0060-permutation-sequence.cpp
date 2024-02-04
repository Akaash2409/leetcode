class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        int factorial = 1;
        for (int i = 1; i < n; i++) {
            factorial *= i;
            v.push_back(i);
        }

        v.push_back(n);

        k--;
        string ans = "";
        while (1) {
            ans += to_string(v[k / factorial]);
            v.erase(v.begin() + k / factorial);
            if (v.size() == 0) break;
            k %= factorial;
            factorial /= v.size();
        }

        return ans;
    }
};