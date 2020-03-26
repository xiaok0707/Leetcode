## 思路

生成下一个排列步骤如下：以 [1,3,5,5,4,2] 为例

1. 从后往前找第一处升序位置 [1,**3,5**,5,4,2]，左边的数字是3，右边是5
2. 从后往前找第一个大于左边数字的数，即4.
3. 将1中左边的数字和2中的数字交换，得到 [1,**4**,5,5,**3**,2].
4. 将右边部分按照升序排序，即可得到下一排列 [1,4,**2,3,5,5**].

### C++

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return;
        int pos=n-1;
        while(pos-1>=0 && nums[pos-1]>=nums[pos]) --pos;
        if(!pos){
            sort(nums.begin(),nums.end());
            return;
        }
        int pos2=n-1;
        while(nums[pos2]<=nums[pos-1]) --pos2;
        swap(nums[pos-1],nums[pos2]);
        sort(nums.begin()+pos,nums.end());
    }
};
```

### Java

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int n=nums.length;
        if(n<2) return;
        int i=n-1;
        while(i-1>=0 && nums[i-1]>=nums[i]) --i;
        if(i>0){
            int j=n-1;
            while(nums[i-1]>=nums[j]) --j;
            swap(nums,i-1,j);
        }
        reverse(nums,i);
    }

    public void swap(int[] nums,int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    
    public void reverse(int[] nums,int pos){
        int i=pos,j=nums.length-1;
        while(i<j){
            swap(nums,i,j);
            ++i;
            --j;
        }
    }
}
```

### Python

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        if n<2:return
        i=n-1
        while i-1>=0 and nums[i-1]>=nums[i]:i-=1
        if i>0:
            j=n-1
            while nums[i-1]>=nums[j]:j-=1
            nums[i-1],nums[j]=nums[j],nums[i-1]
        nums[i:]=[nums[x] for x in range(n-1,i-1,-1)]
```

