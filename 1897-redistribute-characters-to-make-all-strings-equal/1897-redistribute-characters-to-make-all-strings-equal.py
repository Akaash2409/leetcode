class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        """
        Note that when string s1 is a permutation of string word s2, 
        these two strings can Redistribute Characters to Make these 2 Strings Equal
        """
        n=len(words)
        if n==1: return True
        freq=[0]*26
        for s in words:
            for c in s:
                freq[ord(c)-ord('a')]+=1
        
        for f in freq:
            if f%n!=0: return False
        return True
