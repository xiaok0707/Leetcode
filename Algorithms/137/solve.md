## 思路

本质上是统计每一位上二进制1的个数，最后对3求余.

![Picture1.png](https://pic.leetcode-cn.com/28f2379be5beccb877c8f1586d8673a256594e0fc45422b03773b8d4c8418825-Picture1.png)

构造有限状态自动机.

![Picture2.png](https://pic.leetcode-cn.com/ab00d4d1ad961a3cd4fc1840e34866992571162096000325e7ce10ff75fda770-Picture2.png)

0,1,2这三种状态需要用两种二进制位表示，分别是00,01,10，高位用two表示，低位用one表示.

假设当前位是now，根据状态转移关系，写出状态转移式.

```
计算one
if two = 0:(00,01)
	if now = 0: newone = one
	if now = 1: newone = ~one
if two = 1:(10)
	newone = 0

计算two
if one = 0:(10,00)
	if now = 0: newtwo = two
    if now = 1: newtwo = 0
if one = 1:(01)
	newtwo = now
	
化简一下，写成一个条件表达式
newone = ~two ^ (now ^ one)
newtwo = (one & now) | (~one & ~now & two)
```

### C++

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        for(int now:nums){
            int newone=~two & (now^one);
            int newtwo=(one & now) | (~one & ~now & two);
            one=newone;
            two=newtwo;
        }
        return one;
    }
};
```
