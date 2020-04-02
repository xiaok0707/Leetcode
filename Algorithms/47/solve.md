## 思路

生成 n 个不重复元素的全排列，可以看成将 n 个元素放入 n 个位置，从前往后依次在每个位置填入一个当前还没被使用过的元素，然后将其标记为已使用，继续在后续位置填入元素，直到填满 n 个位置，就会生成一个相应的排列.

### C++

```c++
class Solution {
public:
    int n;
    vector<int> nums,used,cur;
    vector<vector<int>> ans;
    
    void dfs(int pos){
        if(pos==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;++i){
            if(!used[i]){
                used[i]=1;
                cur.push_back(nums[i]);
                dfs(pos+1);
                used[i]=0;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->n=nums.size();
        sort(nums.begin(),nums.end());
        this->nums=nums;
        this->used=vector<int>(n,0);
        dfs(0);
        return ans;
    }
};
```

另一种思想：n个元素的全排列 =（取1个元素作为前缀）+（剩下 n-1 个元素的全排列）

递归结束条件：如果只有一个元素的全排列，则说明已经排完，则输出数组.

不断将每个元素作为当前排列中的首个元素，并对剩余元素继续做全排列.

### Java

```java
class Solution {
    int n,nums[];
    List<List<Integer>> ans=new ArrayList<>();

    public void swap(int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }

    public void dfs(int pos){
        if(pos+1==n){
            List<Integer> e=new ArrayList<>();
            for(int i=0;i<n;++i) e.add(nums[i]);
            ans.add(e);
            return;
        }
        for(int i=pos;i<n;++i){
            swap(pos,i);
            dfs(pos+1);
            swap(pos,i);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        this.n=nums.length;
        this.nums=nums;
        dfs(0);
        return ans;
    }
}
```

非递归实现 next_permutation，也就是生成下一个排列的函数，然后从最小的排列开始，不断生成后续所有排列.

具体实现可参考 [Leetcode 31](https://leetcode-cn.com/problems/next-permutation/) .

### Python

```python
def nextPermutation(nums: List[int]) -> bool:
    n=len(nums)
    if n<2: return False
    i=n-2
    while i>=0 and nums[i]>=nums[i+1]: i-=1
    if i<0: return False
    if i>=0:
        j=n-1
        while nums[i]>=nums[j]: j-=1
        nums[i],nums[j]=nums[j],nums[i]
    nums[i+1:]=[nums[x] for x in range(n-1,i,-1)]
    return True

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans=[nums[:]]
        while nextPermutation(nums):
            ans.append(nums[:])
        return ans
```

