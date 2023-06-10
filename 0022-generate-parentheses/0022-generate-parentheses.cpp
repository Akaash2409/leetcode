class Solution {
public:
     vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        unordered_set<string> st;
        vector<string> pre = generateParenthesis(n-1);
        for (auto a : pre) {
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] == '(') {
                    a.insert(a.begin() + i + 1, '(');
                    a.insert(a.begin() + i + 2, ')');
                    st.insert(a);
                    a.erase(a.begin() + i + 1, a.begin() + i + 3);
                }
            }
            st.insert("()" + a);
        }
        return vector<string>(st.begin(), st.end());
    }
};