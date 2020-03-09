class Trie{
    Trie[] nxt;
    int cnt;
    Trie(){
        nxt=new Trie[26];
        for(int i=0;i<26;++i) nxt[i]=null;
        cnt=1;
    }
}

public class Solution {
    Trie root=new Trie();
    int n;

    void Insert(String str){
        Trie cur=root,pnew=null;
        for(int i=0;i<str.length();++i){
            int id=str.charAt(i)-'a';
            if(cur.nxt[id]==null){
                pnew=new Trie();
                cur.nxt[id]=pnew;
            }
            else cur.nxt[id].cnt+=1;
            cur=cur.nxt[id];
        }
    }

    String Search(String str){
        Trie cur=root;
        String ans="";
        for(int i=0;i<str.length();++i){
            int id=str.charAt(i)-'a';
            if(cur.nxt[id].cnt==n){
                ans+=str.charAt(i);
            }
            cur=cur.nxt[id];
        }
        return ans;
    }

    public String longestCommonPrefix(String[] strs) {
        n=strs.length;
        if(0==n) return "";
        for(int i=0;i<n;++i) Insert(strs[i]);
        return Search(strs[0]);
    }
}