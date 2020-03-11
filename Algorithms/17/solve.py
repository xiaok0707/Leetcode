class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        ans = []
        length = len(digits)

        def dfs(pos: int, cur: str):
            if pos==length:
                ans.append(cur)
                return
            for ch in phone[digits[pos]]:
                dfs(pos+1,cur+ch)

        if length>0:
            dfs(0,"")
        return ans