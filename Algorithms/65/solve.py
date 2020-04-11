class Solution:
    def isNumber(self, s: str) -> bool:
        s=s.strip() #去掉两端空格
        if len(s)==0: return False
        if s[0]=='+' or s[0]=='-': s=s[1:] #去掉正负号
        if 'e' in s: #含e
            tmp=s.split('e') #拆分成左右两部分
            if len(tmp)>2: return False
            tmp[0]=tmp[0].replace('.','',1) # 左边除了至多有1个小数点外应该全是数字
            if not tmp[0].isdigit(): return False
            if len(tmp[1])==0: return False # 右边不能是空串
            if tmp[1][0]=='+' or tmp[1][0]=='-': tmp[1]=tmp[1][1:] # 去掉右边的正负号
            return tmp[1].isdigit() # 右边应该全是数字
        else: #不含e
            s=s.replace('.','',1) #去掉1个小数点后应该只剩数字
            return s.isdigit()