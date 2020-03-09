class Solution {
    String[] roman=new String[]{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int[] number=new int[]{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    public int romanToInt(String s) {
        int ans=0,len=s.length();
        for(int i=0;i<len;++i){
            String tmp=""+s.charAt(i);
            if(i+1<len){
                tmp+=s.charAt(i+1);
                boolean flag=false;
                for(int j=0;j<13;++j)
                    if(tmp.equals(roman[j])){
                        ans+=number[j];
                        i+=1;
                        flag=true;
                        break;
                    }
                if(flag) continue;
            }
            for(int j=0;j<13;++j) if(tmp.substring(0,1).equals(roman[j])){
                ans+=number[j];
                break;
            }
        }
        return ans;
    }
}