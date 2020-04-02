class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d={}
        for s in strs:
            cnt=[0]*26
            for ch in s:cnt[ord(ch)-ord('a')]+=1
            if d.get(tuple(cnt))!=None:
                d[tuple(cnt)].append(s)
            else:
                d[tuple(cnt)]=[s]
        return list(d.values())