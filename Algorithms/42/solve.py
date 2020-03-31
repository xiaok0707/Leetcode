class Solution:
    def trap(self, height: List[int]) -> int:
        stack=[]
        ans,n=0,len(height)
        for pos in range(n):
            while len(stack)>0 and height[pos]>height[stack[-1]]:
                tp=stack.pop()
                if len(stack)==0:break
                dist=pos-stack[-1]-1
                ans+=dist*(min(height[pos],height[stack[-1]])-height[tp])
            stack.append(pos)
        return ans