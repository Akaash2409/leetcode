class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int length = 0 ;  // length the world 
        int i = s.length()-1; // i pointer to end the string 

        // check if last string empty decrease  pointer 
        while ( s[i] == ' ' ){
            i--;
        }
        
        // check if pointer not in the first string and not empty 
        while (i >= 0 && s[i] !=' '){
            length ++;
            i--;
        }
        
        return length ;
        
    }
};
