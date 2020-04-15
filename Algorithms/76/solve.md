## 思路

统计各字符出现次数，双指针求解.

### C++

```c++
class Solution {
public:
    int c1[128]={0},c2[128]={0};

    bool check(){
        for(int i=0;i<128;++i) if(c2[i]<c1[i]) return false;
        return true;
    }

    string minWindow(string s, string t) {    
        for(int i=0;i<(int)t.size();++i) ++c1[t[i]];
        int le=0,ri=-1,L=0,R=-1,len=s.length(),minlen=len+1;
        while(ri<len){
            while(ri+1<len && !check()){
                c2[s[ri+1]]+=1;
                ri+=1;
            }
            if(check()){
                if(ri-le+1<minlen){
                    minlen=ri-le+1;
                    L=le;R=ri;
                }
            }
            else break;
            while(check()){
                c2[s[le]]-=1;
                le+=1;
                if(check() && ri-le+1<minlen){
                    minlen=ri-le+1;
                    L=le;R=ri;
                }
            }
        }
        string ans=s.substr(L,R-L+1);
        return ans;
    }
};
```

