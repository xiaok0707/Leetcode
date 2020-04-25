## 思路

$n$ 个点能构成多少种二叉树，卡特兰数.

$n$ 阶递推式 
$$
h(n)=\sum_{i=0}^{n-1}h(i)h(n-1-i)
$$
1 阶递推式
$$
h(n)=\frac{4n-2}{n+1}h(n-1)
$$
通项公式
$$
h(n)=\frac{C_{2n}^{n}}{n+1}
$$


### C++

```c++
class Solution {
public:
    int numTrees(int n) {
        if(n<=0) return 0;
        int ans=1;
        for(int i=1;i<=n;++i){
            ans=1LL*(4*i-2)*ans/(i+1);
        }
        return ans;
    }
};
```

