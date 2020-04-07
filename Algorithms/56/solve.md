## 思路

按左端点升序排序，左端点相等时按右端点升序排序，然后遍历所有区间，将相交的区间合并为一个区间.

### C++

```c++
struct Node{
    int le,ri;
    Node(int l=0,int r=0):le(l),ri(r){}
    bool operator<(const Node& e)const{
        if(le==e.le) return ri<e.ri;
        return le<e.le;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<Node> a(n);
        for(int i=0;i<n;++i) a[i]=Node(intervals[i][0],intervals[i][1]);
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;){
            int le=a[i].le,ri=a[i].ri;
            int j=i+1;
            while(j<n && a[j].le<=ri){
                ri=max(ri,a[j].ri);
                ++j;
            }
            vector<int> tmp;
            tmp.push_back(le);
            tmp.push_back(ri);
            ans.push_back(tmp);
            i=j;
        }
        return ans;
    }
};
```

