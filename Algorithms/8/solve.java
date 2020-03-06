class Solution {
    public int myAtoi(String str) {
        if(str.isEmpty()) return 0;
        int len=str.length(),pos=0;
        while(pos<len && str.charAt(pos)==' ') pos+=1;
        if(pos==len) return 0;
        if(str.charAt(pos)=='+' || str.charAt(pos)=='-'){
            long flag=str.charAt(pos)=='+'?1:-1;
            long ans=0;
            pos+=1;
            if(pos==len) return 0;
            if(!Character.isDigit(str.charAt(pos))) return 0;
            while(pos<len && Character.isDigit(str.charAt(pos))){
                ans=ans*10+Integer.parseInt(String.valueOf(str.charAt(pos)));
                if(ans*flag<Integer.MIN_VALUE) return Integer.MIN_VALUE;
                if(ans*flag>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                pos+=1;
            }
            ans*=flag;
            return (int)ans;
        }
        else if(Character.isDigit(str.charAt(pos))){
            long ans=0;
            while(pos<len && Character.isDigit(str.charAt(pos))){
                ans=ans*10+Integer.parseInt(String.valueOf(str.charAt(pos)));
                if(ans>Integer.MAX_VALUE) return Integer.MAX_VALUE;
                pos+=1;
            }
            return (int)ans;
        }
        else return 0;
    }
}