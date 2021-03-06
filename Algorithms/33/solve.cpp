class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(0==n) return -1;
        if(1==n) return nums[0]==target?0:-1;
        if(nums[0]<nums[n-1]){
            int pos=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            return pos!=n && nums[pos]==target?pos:-1;
        }
        int le=0,ri=n-1;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            if(nums[mid]>nums[le]) le=mid;
            else ri=mid;
        }
        if(target>=nums[0]){
            int pl=0,pr=le+1;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
        else{
            int pl=ri,pr=n;
            while(pl+1<pr){
                int pmid=(pl+pr)>>1;
                if(nums[pmid]<=target) pl=pmid;
                else pr=pmid;
            }
            return nums[pl]==target?pl:-1;
        }
    }
};