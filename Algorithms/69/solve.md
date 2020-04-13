## 思路

二分开根号.

### C++

```c++
class Solution {
public:
    int mySqrt(int x) {
        int le=0,ri=50000;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(1LL*mid*mid<=x) le=mid;
            else ri=mid;
        }
        return le;
    }
};
```

