## 思路

简单模拟.

### C++

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(i<n){
            if(i+1<n){
                if(nums[i]==nums[i+1]){
                    nums[j]=nums[j+1]=nums[i];
                    while(i<n && nums[i]==nums[j]) ++i;
                    j+=2;
                }
                else{
                    nums[j++]=nums[i++];
                }
            }
            else{
                nums[j++]=nums[i++];
            }
        }
        return j;
    }
};
```

