class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0,j=0,ans=0,len=s.length();
        Map<Character,Boolean> vis=new HashMap<>();
        vis.clear();
        for(char ch:s.toCharArray()) vis.put(ch,false);
        while(i<len && j<len){
            while(j<len && !vis.get(s.charAt(j))){
                vis.put(s.charAt(j),true);
                ++j;
            }
            ans=Math.max(ans,j-i);
            if(j<len){
                while(s.charAt(i)!=s.charAt(j)){
                    vis.put(s.charAt(i),false);
                    ++i;
                }
                vis.put(s.charAt(i),false);
                ++i;
            }
        }
        return ans;
    }
}