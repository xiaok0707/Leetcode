class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        s=str(x)
        l=len(s)
        for i in range(0,l//2):
            if s[i]!=s[l-1-i]:
                return False
        return True