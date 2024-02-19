class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        if(n == 1) return true;
        return n % 2 == 0 and isPowerOfTwo(n / 2);
    }
};