## 思路

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)

依次考虑每个位置的储水量，对于某个位置 i 来说，有一部分是黑色柱子，有一部分是水，题目输入的是柱子的高度，那么位置 i 的柱子上面还有多少水？这个应该去看位置 i 左边柱子的最大高度 le_max，和右边柱子的最大高度ri_max，存在这两根更高的柱子才能让位置 i 储水，储水量是 $min(le\_max,ri\_max)-height[i]$ .

所以可以提前预处理前缀最大值和后缀最大值，然后遍历一遍原序列即可求出总的储水量.

时间、空间复杂度都是 $O(n)$.

### C++

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        vector<int> le(n,height[0]),ri(n,height[n-1]);
        for(int i=1;i<n;++i) le[i]=max(le[i-1],height[i]);
        for(int i=n-2;i>=0;--i) ri[i]=max(ri[i+1],height[i]);
        int ans=0;
        for(int i=0;i<n;++i) ans+=min(le[i],ri[i])-height[i];
        return ans;
    }
};
```

可以稍加改进，只用 $O(1)$ 的空间. 方法是使用左右指针 $le,ri$ 指向当前的左右两个柱子，同时用两个变量 $le\_max,ri\_max$ 维护 $max(height[0...le]),max(height[ri...n-1])$，每次首先判断 $le,ri$ 两个柱子的大小关系，如果 $height[le]$ 更小，那就更新并使用 $le\_max$ 计算 $le$ 处的答案，因为此时 $le\_max$ 一定小于 $ri\_max$，否则在 $le$  之前的某个位置一定 $i$ 会有 $height[i]>height[ri]$，那么就应当先计算 $ri$ 而不是 $le$ 了. 反之如果 $height[ri]$ 更小，则更新并使用 $ri\_max$ 计算 $ri$ 处的答案.

时间复杂度 $O(n)$，空间复杂度 $O(1)$.

### Java

```java
class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int ans=0,le_max=0,ri_max=0,le=0,ri=n-1;
        while(le<ri){
            if(height[le]<height[ri]){
                if(height[le]>le_max) le_max=height[le];
                ans+=le_max-height[le];
                le+=1;
            }
            else{
                if(height[ri]>ri_max) ri_max=height[ri];
                ans+=ri_max-height[ri];
                ri-=1;
            }
        }
        return ans;
    }
}
```

也可以使用栈来处理，从左往右遍历，如果当前柱子高度小于等于栈顶高度，说明该柱子的储水量受前一个柱子的影响，将其下标加入栈中，否则依次从栈中弹出比当前高度更小的柱子，计算答案.

### Python

```python
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
```

