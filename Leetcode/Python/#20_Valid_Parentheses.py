class Solution:
    def isValid(self, s: str) -> bool:
        d = {'}' : '{', ']' : '[', ')' : '('}
        stack = []
        for ch in s:
            if ch in d:
                if not stack or stack[-1] != d[ch]:
                    return False
                else:
                    stack.pop()
            else:
                stack.append(ch)
        return not stack
