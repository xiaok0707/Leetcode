class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> v(numRows);
        int row=0;
        bool down=true;
        for(int i=0;i<(int)s.size();++i){
            v[row]+=s[i];
            if(down){
                if(row+1==numRows){
                    row-=1;
                    down=false;
                }
                else row+=1;
            }
            else{
                if(row==0){
                    row+=1;
                    down=true;
                }
                else row-=1;
            }
        }
        string ans="";
        for(int i=0;i<numRows;++i) ans+=v[i];
        return ans;
    }
};