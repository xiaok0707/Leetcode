class Solution:
    def simplifyPath(self, path: str) -> str:
        path=path.split('/')
        path=[e for e in path if e!='']
        ans=[]
        for e in path:
            if e=='.': continue
            if e=='..':
                if len(ans): ans.pop()
            else:
                ans.append(e)
        return '/'+'/'.join(ans)