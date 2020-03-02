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