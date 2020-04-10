class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n=len(digits)
        carry=1
        for i in range(n-1,-1,-1):
            tmp=(digits[i]+carry)%10
            carry=(digits[i]+carry)//10
            digits[i]=tmp
        if carry:
            digits.insert(0,carry)
        return digits