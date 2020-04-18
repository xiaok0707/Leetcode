class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n=len(heights)
        le,ri=[0 for i in range(n)],[0 for i in range(n)]
        stack=[]
        for i in range(n):
            while len(stack)>0 and heights[stack[-1]]>=heights[i]: stack.pop()
            if len(stack)==0: le[i]=-1
            else: le[i]=stack[-1]
            stack.append(i)
        stack=[]
        for i in range(n-1,-1,-1):
            while len(stack)>0 and heights[stack[-1]]>=heights[i]: stack.pop()
            if len(stack)==0: ri[i]=n
            else: ri[i]=stack[-1]
            stack.append(i)
        ans=0
        for i in range(n):
            ans=max(ans,(ri[i]-le[i]-1)*heights[i])
        return ans