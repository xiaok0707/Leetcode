class Solution {
public:
    string roman[13]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int number[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string intToRoman(int num) {
        string ans="";
        int pos=12;
        while(num){
            while(num>=number[pos]){
                num-=number[pos];
                ans+=roman[pos];
            }
            --pos;
        }
        return ans;
    }
};