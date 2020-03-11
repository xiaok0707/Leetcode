class Solution {
    Map<String, String> phone = new HashMap<String, String>() {{
        put("2", "abc");
        put("3", "def");
        put("4", "ghi");
        put("5", "jkl");
        put("6", "mno");
        put("7", "pqrs");
        put("8", "tuv");
        put("9", "wxyz");
    }};
    List<String> ans=new LinkedList<>();
    String digits,cur;
    int len;

    public void dfs(int pos){
        if(pos==len){
            ans.add(cur);
            return;
        }
        String key=digits.substring(pos,pos+1);
        for(int i=0;i<phone.get(key).length();++i){
            char ch=phone.get(key).charAt(i);
            cur+=ch;
            dfs(pos+1);
            cur=cur.substring(0,cur.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {
        this.digits=digits;
        len=digits.length();
        ans.clear();
        cur="";
        if(len>0) dfs(0);
        return ans;
    }
}