class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),le=newInterval[0],ri=newInterval[1];
        vector<vector<int>> ans;
        if(!n){
            ans.push_back(newInterval);
            return ans;
        }
        if(ri<intervals[0][0]){
            ans.push_back(newInterval);
        }
        for(int i=0;i<n;){
            if(intervals[i][1]<le){
                ans.push_back(intervals[i]);
                ++i;
            }
            else if(intervals[i][0]>ri){
                if(i-1>=0 && intervals[i-1][1]<le){
                    ans.push_back(newInterval);
                }
                ans.push_back(intervals[i]);
                ++i;
            }
            else{
                int j=i,L=le,R=ri;
                while(j<n && intervals[j][0]<=ri){
                    L=min(L,intervals[j][0]);
                    R=max(R,intervals[j][1]);
                    ++j;
                }
                i=j;
                vector<int> tmp(2);
                tmp[0]=L;tmp[1]=R;
                ans.push_back(tmp);
            }
        }
        if(le>intervals[n-1][1]){
            ans.push_back(newInterval);
        }
        return ans;
    }
};