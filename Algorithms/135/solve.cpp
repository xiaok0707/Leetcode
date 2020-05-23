class Solution {
public:
    int n;
    vector<int> a,cnt;

    int calcle(int pos){
        int num=1;
        while(pos-1>=0 && a[pos-1]>a[pos]){
            cnt[pos-1]=max(cnt[pos-1],++num);
            --pos;
        }
        return pos;
    }

    int calcri(int pos){
        int num=1;
        while(pos+1<n && a[pos+1]>a[pos]){
            cnt[pos+1]=max(cnt[pos+1],++num);
            ++pos;
        }
        return pos;
    }

    int candy(vector<int>& ratings) {
        a=ratings;
        n=a.size();
        cnt=vector<int>(n,0);

        int i=0;
        while(i<n){
            while(i+1<n && a[i+1]<a[i]) ++i;
            cnt[i]=1;
            calcle(i);
            i=calcri(i)+1;
        }

        int ans=0;
        for(int e:cnt) ans+=e;
        return ans;
    }
};