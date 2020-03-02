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