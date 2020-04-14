class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(!n) return false;
        int m=matrix[0].size();
        if(!m) return false;
        if(matrix[0][0]>target) return false;
        int le=0,ri=n*m;
        while(le+1<ri){
            int mid=(le+ri)>>1;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]<=target) le=mid;
            else ri=mid;
        }
        int r=le/m,c=le%m;
        return matrix[r][c]==target;
    }
};