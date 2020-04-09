## 思路

逆康拓展开. 

康托展开是一个双射，那么一定可以通过康托展开值求出原排列，即可以求出n的全排列中第x大排列.

如n=5,x=96时：

```
首先用96-1得到95，说明x之前有95个排列.(将此数本身减去1)
用95去除4! 得到3余23，说明有3个数比第1位小，所以第一位是4.
用23去除3! 得到3余5，说明有3个数比第2位小，所以是4，但是4已出现过，因此是5.
用5去除2!得到2余1，类似地，这一位是3.
用1去除1!得到1余0，这一位是2.
最后一位只能是1.
所以这个数是45321.
```

可以用线段树优化至 $(nlogn)$，但这道题 n 非常小，无需优化.

### C++

```c++
const int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};

class Solution {
public:
    string getPermutation(int n, int k) {
        k-=1;
        string ans="";
        vector<bool> used(n+1,false);
        for(int i=1;i<=n;++i){
            int num=k/fac[n-i]+1;
            k%=fac[n-i];
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(!used[j]){
                    ++cnt;
                    if(cnt==num){
                        used[j]=true;
                        ans+='0'+j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```

