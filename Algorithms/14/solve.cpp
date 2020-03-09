struct Trie{
    Trie* nxt[26];
    int cnt;
    Trie(int cnt=1){
        for(int i=0;i<26;++i) nxt[i]=NULL;
        this->cnt=cnt;
    }
}*root;

int n;

void insert(string s){
    Trie *cur=root,*pnew;
    for(int i=0;s[i];++i){
        int id=s[i]-'a';
        if(!cur->nxt[id]){
            pnew=new Trie();
            cur->nxt[id]=pnew;
        }
        else cur->nxt[id]->cnt+=1;
        cur=cur->nxt[id];
    }
}

string search(string s){
    string ans="";
    Trie* cur=root;
    for(int i=0;s[i];++i){
        int id=s[i]-'a';
        if(cur->nxt[id]->cnt==n){
            ans+=s[i];
        }
        cur=cur->nxt[id];
    }
    return ans;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        n=strs.size();
        if(!n) return "";
        root=new Trie(0);
        for(int i=0;i<n;++i) insert(strs[i]);
        return search(strs[0]);
    }
};