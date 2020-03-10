## 思路

大体思路是先对原数组排序，然后遍历排序后的数组，把遍历到的元素的相反数当成是一个目标值 val，在该元素的后面再去寻找两个数，使它们的和为 val.

重点在于去重，首先在遍历到同样的 val 值时要跳过。对于某个val，设置两个指针 le 和 ri，le 指向当前遍历到元素的后一个位置，ri 指向数组的最后一个位置，然后根据 le 和 ri 对应元素之和与 val 的大小关系来对 le 和 ri 进行调整，如果当前的和小于 val 则令 le+1，大于 val 则让 ri-1. 当 le 和 ri 对应元素之和与 val 相等时记录答案，同时将 le 增加直至指向更大的数，将 ri 减小直至指向更小的数，起到去重的效果.

优化：在排序后进行遍历的时候，如果遍历到了一个正值，那么 val 就是负数，而之后的数字也一定都是正数，所以不会有解，可以直接退出循环.

时间复杂度 $O(n^2)$

### C++

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        if(len<3 || nums[0]>0 || nums[len-1]<0) return {};
        for(int pos=0;pos<len;++pos){
            if(nums[pos]>0) break;
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int val=-nums[pos];
            int le=pos+1,ri=len-1;
            while(le<ri){
                if(nums[le]+nums[ri]==val){
                    ans.push_back({nums[pos],nums[le],nums[ri]});
                    while(le<ri && nums[le+1]==nums[le]) ++le;
                    while(le<ri && nums[ri-1]==nums[ri]) --ri;
                    ++le;--ri;
                }
                else{
                    if(nums[le]+nums[ri]<val) ++le;
                    else --ri;
                }
            }
        }
        return ans;
    }
};
```

### Java

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans=new LinkedList<>();
        ans.clear();
        int len=nums.length;
        Arrays.sort(nums);

        for(int pos=0;pos<len;++pos){
            if(nums[pos]>0) break;
            if(pos>0 && nums[pos-1]==nums[pos]) continue;
            int val=-nums[pos];
            int le=pos+1,ri=len-1;
            while(le<ri){
                if(nums[le]+nums[ri]==val){
                    List<Integer> e=new LinkedList<>();
                    e.add(nums[pos]);
                    e.add(nums[le]);
                    e.add(nums[ri]);
                    ans.add(e);
                    while(le<ri && nums[le+1]==nums[le]) ++le;
                    ++le;
                    while(le<ri && nums[ri-1]==nums[ri]) --ri;
                    --ri;
                }
                else{
                    if(nums[le]+nums[ri]<val) ++le;
                    else --ri;
                }
            }
        }
        return ans;
    }
}
```

### Python

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        list.sort(nums)
        L=len(nums)
        for pos in range(L):
            if nums[pos]>0:
                break
            if pos>0 and nums[pos]==nums[pos-1]:
                continue
            val=-nums[pos]
            le=pos+1
            ri=L-1
            while le<ri:
                if nums[le]+nums[ri]==val:
                    ans.append([nums[pos],nums[le],nums[ri]])
                    while le<ri and nums[le+1]==nums[le]:
                        le+=1
                    while le<ri and nums[ri-1]==nums[ri]:
                        ri-=1
                    le+=1
                    ri-=1
                else:
                    if nums[le]+nums[ri]<val:
                        le+=1
                    else:
                        ri-=1
        return ans
```

