class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        seen = set()
        L = 0
        for R in range(len(s)):
            while s[R] in seen:
                seen.remove(s[L])
                L += 1
            seen.add(s[R])
            maxLen = max(maxLen, R-L+1)
        return maxLen
