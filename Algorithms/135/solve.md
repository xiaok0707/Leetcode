## 思路

自己的思路：找极小值点，从极小值点向两端拓展直到不再递增，在这一过程中依次分配 1,2,3... 个糖果，对于某些极大值点，可能存在被两个方向的极小值点拓展到，所以要取一下最大值. 时间空间均为 $O(n)$.

### C++

```c++
class Solution {
public:
    int n;
    vector<int> a,cnt;

    int calcle(int pos){
        int num=1;
        while(pos-1>=0 && a[pos-1]>a[pos]){
            cnt[pos-1]=max(cnt[pos-1],++num);
            --pos;
        }
        return pos;
    }

    int calcri(int pos){
        int num=1;
        while(pos+1<n && a[pos+1]>a[pos]){
            cnt[pos+1]=max(cnt[pos+1],++num);
            ++pos;
        }
        return pos;
    }

    int candy(vector<int>& ratings) {
        a=ratings;
        n=a.size();
        cnt=vector<int>(n,0);

        int i=0;
        while(i<n){
            while(i+1<n && a[i+1]<a[i]) ++i;
            cnt[i]=1;
            calcle(i);
            i=calcri(i)+1;
        }

        int ans=0;
        for(int e:cnt) ans+=e;
        return ans;
    }
};
```

### Python

最好理解的思路，可以把题目中的要求看成两个要求：

1. 对于某个人而言，如果他比他左边人得分高，那么他的糖果数要>他左边的人
2. 对于某个人而言，如果他比他右边人得分高，那么他的糖果数要>他右边的人

最初给每个人都分配1个糖果，然后分别解决上面的两个问题（从左到右扫描一次，再从右到左扫描一次），最后对每个人取上面两个问题解的最大值，时间空间均为 $O(n)$.

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        le,ri=[1]*n,[1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                le[i]=le[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                ri[i]=ri[i+1]+1
        
        ans=0
        for i in range(n):
            ans+=max(le[i],ri[i])
        return ans
```

糖果的局部分配一定是连续的 1,2,3...,k-1,k 或者是连续的 k,k-1,...3,2,1 的形式，峰顶需要取最大，可以以 上坡+下坡 为一组单位遍历整个数组，统计答案，细节比较复杂，很难想到. 时间 $O(n)$，空间 $O(1)$.

### Java

```java
public class Solution {
    public int count(int n) {
        return (n * (n + 1)) / 2;
    }
    public int candy(int[] ratings) {
        if (ratings.length <= 1) {
            return ratings.length;
        }

        int candies = 0;
        int up = 0;
        int down = 0;
        int old_slope = 0;

        for (int i = 1; i < ratings.length; i++) {
            int new_slope = (ratings[i] > ratings[i - 1]) ? 1 : (ratings[i] < ratings[i - 1] ? -1 : 0);
            if ((old_slope > 0 && new_slope == 0) || (old_slope < 0 && new_slope >= 0)) {
                candies += count(up) + count(down) + Math.max(up, down);
                up = 0;
                down = 0;
            }
            if (new_slope > 0)
                up++;
            if (new_slope < 0)
                down++;
            if (new_slope == 0)
                candies++;

            old_slope = new_slope;
        }
        candies += count(up) + count(down) + Math.max(up, down) + 1;
        return candies;
    }
}
```

