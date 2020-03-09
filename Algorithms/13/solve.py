class Solution:
    def romanToInt(self, s: str) -> int:
        roman = ['I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M']
        number = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        ans=i=0
        while i<len(s):
            tmp=s[i]
            if i+1<len(s):
                tmp+=s[i+1]
                flag=False
                for j in range(13):
                    if roman[j]==tmp:
                        ans+=number[j]
                        i+=2
                        flag=True
                        break
                if flag:
                    continue
            for j in range(13):
                if roman[j]==tmp[0]:
                    ans+=number[j]
                    i+=1
                    break
        return ans

    