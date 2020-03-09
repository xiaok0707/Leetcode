class Solution {
public:
    string roman[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int number[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

    int romanToInt(string s) {
        int ans=0,len=s.length();
        for(int i=0;i<len;++i){
            string tmp=s.substr(i,1);
            if(i+1<len){
                tmp+=s[i+1];
                bool flag=false;
                for(int j=0;j<13;++j) if(tmp==roman[j]){
                    ans+=number[j];
                    i+=1;
                    flag=true;
                    break;
                }
                if(flag) continue;
            }
            for(int j=0;j<13;++j) if(tmp.substr(0,1)==roman[j]){
                ans+=number[j];
                break;
            }
        }
        return ans;
    }
};