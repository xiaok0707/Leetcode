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