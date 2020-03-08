## 思路

简化一下题意，给定一个数组 $a[1,n]$ ，找出 $(i,j),i<j$，使得 $(j-i)×min(a[i],a[j])$ 的值最大，求这个最大值.

可以从两边向中间搜索，首先令 $le$ 指向 $a[1]$ ，令 $ri$ 指向 $a[n]$，然后每次首先更新当前答案，然后比较 $a[le]$ 和 $a[ri]$ 的大小关系，如果 $a[le]<a[ri]$ ，那么说明当 $i=le$ 时，$j=ri$ 一定比 $j=ri-1,j=ri-2...$ 更优，可以直接令 $le+1$ ，指向下一个值，继续统计。反之，如果 $a[le]>a[ri]$ ，也是一样的道理。

时间复杂度 $O(n)$

### C++

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int le=0,ri=n-1,ans=0;
        while(le<ri){
            ans=max(ans,(ri-le)*min(height[le],height[ri]));
            if(height[le]<height[ri]) ++le;
            else --ri;
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int le=0,ri=n-1,ans=0;
        while(le<ri){
            ans=Math.max(ans,(ri-le)*Math.min(height[le],height[ri]));
            if(height[le]<height[ri]) ++le;
            else --ri;
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        le=ans=0
        ri=len(height)-1
        while le<ri:
            ans=max(ans,(ri-le)*min(height[le],height[ri]))
            if height[le]<height[ri]:
                le+=1
            else:
                ri-=1
        return ans
```

