class Solution:
    def intToRoman(self, num: int) -> str:
        roman = ['I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M']
        number = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        ans=''
        for i in range(len(number)-1,-1,-1):
            if num>=number[i]:
                ans+=num//number[i]*roman[i]
                num%=number[i]
        return ans