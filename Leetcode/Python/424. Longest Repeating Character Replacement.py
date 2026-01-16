class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        chars = Counter()
        L = 0
        maxFreq = 0
        res = 0
        for R in range(len(s)):
            chars[s[R]] += 1
            maxFreq = max(maxFreq, chars[s[R]])
            while (R - L - maxFreq + 1) > k:
                chars[s[L]] -= 1
                L += 1
            res = max(res, R - L + 1)
        return res
