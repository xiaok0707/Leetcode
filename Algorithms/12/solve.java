class Solution {
    String[] roman=new String[]{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int[] number=new int[]{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    public String intToRoman(int num) {
        String ans="";
        int pos=12;
        while(num>0){
            while(num>=number[pos]){
                num-=number[pos];
                ans+=roman[pos];
            }
            --pos;
        }
        return ans;
    }
}