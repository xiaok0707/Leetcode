## 思路

利用异或运算的性质：
$$
x \oplus 0 = x,\ \  x \oplus x = 0
$$
用一个变量记录所有数的异或结果即可.

### C++

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;++i) ans^=nums[i];
        return ans;
    }
};
```
