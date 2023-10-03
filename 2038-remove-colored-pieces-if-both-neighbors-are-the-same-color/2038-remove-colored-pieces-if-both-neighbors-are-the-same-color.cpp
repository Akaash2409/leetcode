class Solution {
public:
    
    bool winnerOfGame(string colors) {
        
        vector<int> A, B;
    
        char last_color = '-';

        for(char c: colors) {
            if(last_color == c) {
                if(c == 'A') ++A.back();
                else ++B.back();
            }
            else {
                if(c == 'A') A.push_back(1);
                else B.push_back(1);
            }
            last_color = c;
        }

        int alice = 0,  bob = 0;

        for(int &a: A) alice += max(0, a - 2);

        for(int &b: B) bob += max(0, b - 2);

        return alice > bob;
    }
};