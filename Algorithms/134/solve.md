## 思路

可以将两个数组 $gas$ 和 $cost$ 看成一个数组，即 $ a[i]=gas[i]-cost[i] $，从某点出发，统计 $a$ 的和 $sum$，当此时的 $sum<0$ 时说明无法通行.

从每一个点出发，依次扫描复杂度是 $O(n^2)$，可以进行如下优化.

假设结点总数为 $n$，从结点 0 出发，$sum$ 即为 $a$ 的前缀和，即 $sum[i]=a[0]+a[1]+...a[i]$.

**求出 $sum$ 的最小值，假设为 $sum[i]$，如果此时的 $sum[n-1]>=0$ 那么只需要从 $i+1$ 位置出发，一定合法**.

反证法证明如下：

假设从 $i+1$ 出发，如果在 $i+1$ 的后面某个位置 $j$ 出现了无法通行的情况，即 $sum[j]-sum[i]<0$，移项得 $sum[j]<sum[i]$，这是不可能的，因为 $sum[i]$ 是最小值，前后矛盾.

如果在 $i+1$ 的前面某个位置出现了无法通行的情况，即 $sum[n-1]-sum[i]+sum[j]<0$，移项得 $(sum[j]-sum[i])+sum[n-1]<0$，也是不可能的，因为假设中 $sum[n-1]>=0$ 且 $sum[i]$ 是最小值，那么也一定有 $sum[j]-sum[i]>=0$ ，两个非负项相加一定还是非负的，前后矛盾.

优化之后的方法，只需要求出 $sum$ 以及它的最小值下标，时间复杂度 $O(n)$.

### C++

```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0,id=0,minsum=INT_MAX;
        for(int i=0;i<n;++i){
            sum+=gas[i]-cost[i];
            if(sum<minsum){
                id=i;
                minsum=sum;
            }
        }
        return sum>=0?(id+1)%n:-1;
    }
};
```
