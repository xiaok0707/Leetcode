class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0,id=0,minsum=INT_MAX;
        for(int i=0;i<n;++i){
            sum+=gas[i]-cost[i];
            if(sum<minsum){
                id=i;
                minsum=sum;
            }
        }
        return sum>=0?(id+1)%n:-1;
    }
};