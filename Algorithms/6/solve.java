import java.util.Vector;

class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        Vector<String> v=new Vector<>(numRows);
        for(int i=0;i<numRows;++i) v.add("");
        int row=0;
        boolean down=true;
        for(int i=0;i<s.length();++i){
            String str=v.get(row);
            v.set(row,str+s.charAt(i));
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
        String ans="";
        for(int i=0;i<numRows;++i) ans+=v.get(i);
        return ans;
    }
}