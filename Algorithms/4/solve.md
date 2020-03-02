## 思路

比较灵活的二分思想。

如果某个有序数组长度是奇数，那么其中位数就是中间元素，如果是偶数，那么中位数就是中间两个数字的平均值。假设两个有序数组的长度分别为m和n，由于两个数组长度之和 m+n 的奇偶不确定，为了简化代码，在混合后的数组找第 $\lfloor\frac{m+n+1}{2}\rfloor$ 个元素，和第 $\lfloor\frac{m+n+1}{2}\rfloor$ 个元素，然后求其平均值。若 m+n 为奇数的话，那么 $\lfloor\frac{m+n+1}{2}\rfloor$$ 和 $$\lfloor\frac{m+n+1}{2}\rfloor$ 的值相等，相当于两个相同的数字相加再除以2，还是其本身。

具体求解的时候，定义一个函数findKth，功能是寻找两个有序数组中的第k个元素。实现时可以采用二分思想，对参数k进行二分处理，具体做法如下：分别在nums1数组中和nums2数组中找到各自的第 $ \lfloor \frac{k}{2} \rfloor$ 个元素，比较它们的大小，如果nums1中第 $ \lfloor \frac{k}{2} \rfloor$ 个元素更小，说明原nums1的前 $ \lfloor \frac{k}{2} \rfloor$ 个元素一定都不是混合后数组中的第 $k$ 个元素，于是可以忽略nums1中的前 $ \lfloor \frac{k}{2} \rfloor$ 个元素，在nums1剩下的部分和nums2中找它们混合后的第 $k-\lfloor \frac{k}{2} \rfloor$ 个元素，反之如果nums2中第 $ \lfloor \frac{k}{2} \rfloor$ 个元素更小，忽略nums2中的前 $ \lfloor \frac{k}{2} \rfloor$ 个元素即可。

举例，nums1={1,3,6,9}，nums2={2,4,5,8}，k=4，首先 k/2=2，分别找nums1和nums2的第2个元素，nums1(2)=3，nums2(2)=4，nums1(2)<nums2(2)，所以nums1中的前两个元素1和3肯定不是混合之后的中位数，接下来将问题变成，nums1={6,9}，nums2={2,4,5,8}，k=2，k的规模减半，代码中递归实现。

特殊情况，如果nums1的长度小于 $ \lfloor \frac{k}{2} \rfloor$，则可直接忽略nums2的前 $ \lfloor \frac{k}{2} \rfloor$ 个元素，反之亦然。比如 nums1={3}，nums2={2,4,5,6,7}，k=4，分别在 nums1 和 nums2 中找第2个数字，而 nums1 中只有一个数字，不存在第二个数字，则 nums2 中的前2个数字可以直接跳过，因为要求的是混合后数组的第4个数字，不管 nums1 中的数字是大是小，混合后的第4个数字绝不会出现在 nums2 的前两个数字中，所以可以直接跳过。

递归终止条件：

1. k=1时，直接比较nums1和nums2的第1个元素大小即可
2. 当nums1或nums2为空时，直接返回非空数组的第k个元素即可

时间复杂度 $O(log(m+n))$

### C++

```c++
class Solution {
public:
    double findKth(vector<int>& nums1,vector<int>& nums2,int pos1,int pos2,int k){
        //返回两个有序数组nums1(从pos1下标开始),nums2(从pos2下标开始)混合后的第k个元素
        if(pos1>=(int)nums1.size()) return nums2[pos2+k-1];
        if(pos2>=(int)nums2.size()) return nums1[pos1+k-1];
        if(k==1) return nums1[pos1]<=nums2[pos2]?nums1[pos1]:nums2[pos2];

        int midVal1=pos1+k/2-1<(int)nums1.size()?nums1[pos1+k/2-1]:INT_MAX;
        int midVal2=pos2+k/2-1<(int)nums2.size()?nums2[pos2+k/2-1]:INT_MAX;

        if(midVal1<=midVal2) return findKth(nums1,nums2,pos1+k/2,pos2,k-k/2);
        else return findKth(nums1,nums2,pos1,pos2+k/2,k-k/2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size();
        return 1.0*(findKth(nums1,nums2,0,0,(len1+len2+1)/2)+findKth(nums1,nums2,0,0,(len1+len2+2)/2))/2.0;
    }
};
```

### Java

```java
class Solution {
    public int findKth(int[] nums1,int[] nums2,int pos1,int pos2,int k){
        if(pos1>=nums1.length) return nums2[pos2+k-1];
        if(pos2>=nums2.length) return nums1[pos1+k-1];
        if(1==k) return nums1[pos1]<nums2[pos2]?nums1[pos1]:nums2[pos2];

        int midVal1=pos1+k/2-1<nums1.length?nums1[pos1+k/2-1]:Integer.MAX_VALUE;
        int midVal2=pos2+k/2-1<nums2.length?nums2[pos2+k/2-1]:Integer.MAX_VALUE;

        if(midVal1<midVal2) return findKth(nums1,nums2,pos1+k/2,pos2,k-k/2);
        else return findKth(nums1,nums2,pos1,pos2+k/2,k-k/2);
    }

    public double findMedianSortedArrays(int[] nums1,int[] nums2){
        int len1= nums1.length,len2=nums2.length;
        return 1.0*(findKth(nums1,nums2,0,0,(len1+len2+1)/2)+findKth(nums1,nums2,0,0,(len1+len2+2)/2))/2;
    }
}
```

### Python

```python
class Solution:
    def findKth(self,nums1:List[int],nums2:List[int],pos1:int,pos2:int,k:int)->int:
        if pos1>=len(nums1):
            return nums2[pos2+k-1]
        if pos2>=len(nums2):
            return nums1[pos1+k-1]
        if 1==k:
            return min(nums1[pos1],nums2[pos2])

        midVal1=midVal2=0x7fffffff
        if pos1+k//2-1<len(nums1):
            midVal1=nums1[pos1+k//2-1]
        if pos2+k//2-1<len(nums2):
            midVal2=nums2[pos2+k//2-1]

        if midVal1<midVal2:
            return self.findKth(nums1,nums2,pos1+k//2,pos2,k-k//2)
        else:
            return self.findKth(nums1,nums2,pos1,pos2+k//2,k-k//2)

    def findMedianSortedArrays(self,nums1:List[int],nums2:List[int])->float:
        len1=len(nums1)
        len2=len(nums2)
        return (self.findKth(nums1,nums2,0,0,(len1+len2+1)//2)+self.findKth(nums1,nums2,0,0,(len1+len2+2)//2))/2
```

