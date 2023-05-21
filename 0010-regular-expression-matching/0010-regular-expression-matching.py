class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        if not s and len(p) == 1:
            return False

        len_row = len(s) + 1
        len_col = len(p) + 1

        dp = [[False for col in range(len_col)] for row in range(len_row)]

        dp[0][0] = True

        for col in range(2, len_col):
            j = col - 1
            if p[j] == "*":
                dp[0][col] = dp[0][col - 2]

        for row in range(1, len_row):
            i = row - 1
            for col in range(1, len_col):
                j = col - 1

                if s[i] == p[j] or p[j] == ".":
                    dp[row][col] = dp[row - 1][col - 1]

                elif p[j] == "*":
                    if p[j - 1] == s[i] or p[j - 1] == ".":
                        dp[row][col] = dp[row - 1][col] or dp[row][col - 2]
                    else:
                        dp[row][col] = dp[row][col - 2]
                else:
                    dp[row][col] = False

        return dp[len_row - 1][len_col - 1]