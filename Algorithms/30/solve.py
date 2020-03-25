class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:return []
        from collections import Counter
        one_len = len(words[0])
        size=len(words)
        words=Counter(words)
        ans=[]
        for i in range(one_len):
            cnt,le,ri=0,i,i
            cur=Counter()
            while ri+one_len<=len(s):
                r_word=s[ri:ri+one_len]
                cur[r_word]+=1
                cnt+=1
                ri+=one_len
                while cur[r_word]>words[r_word]:
                    l_word=s[le:le+one_len]
                    cur[l_word]-=1
                    cnt-=1
                    le+=one_len
                if cnt==size:
                    ans.append(le)
        return ans