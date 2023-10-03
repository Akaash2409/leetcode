class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
       
		if (A.empty()) return 0;
		int sum = accumulate(A.begin(), A.end(), 0);//25
		int j = 0;
		int max = 0;
		max = accumulate(A.begin(), A.end(), max, [&j](int max, int elem) {return  max + elem * j++; });
		int k = A.size() - 1;
		int last = max;
		for (int i = 0; i != k; ++i)
		{
			last = last - k * A[k - i] + sum - A[k - i];
			max = max>last ? max : last;
		}
		return max;
    }
};