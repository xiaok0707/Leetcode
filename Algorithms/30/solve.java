class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans=new ArrayList<>();
        if(s.isEmpty() || 0==words.length) return ans;
        int one_len=words[0].length();
        int all_num=words.length;
        HashMap<String,Integer> words_map=new HashMap<>();
        for(int i=0;i<all_num;++i)
            words_map.put(words[i],1+words_map.getOrDefault(words[i],0));
        for(int i=0;i<one_len;++i){
            int cnt=0,le=i,ri=i;
            HashMap<String,Integer> cur_map=new HashMap<>();
            while(ri+one_len<=s.length()){
                String r_word=s.substring(ri,ri+one_len);
                cur_map.put(r_word,1+cur_map.getOrDefault(r_word,0));
                cnt+=1;
                ri+=one_len;
                while(cur_map.getOrDefault(r_word,0)>words_map.getOrDefault(r_word,0)){
                    String l_word=s.substring(le,le+one_len);
                    cur_map.put(l_word,cur_map.get(l_word)-1);
                    cnt-=1;
                    le+=one_len;
                }
                if(cnt==all_num) ans.add(le);
            }
        }
        return ans;
    }
}