class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len=s.length();
        for(int i=0;i<len;++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(s[i]==')'){
                    if(st.size() && st.top()=='(') st.pop();
                    else return false;
                }
                else if(s[i]==']'){
                    if(st.size() && st.top()=='[') st.pop();
                    else return false;
                }
                else{
                    if(st.size() && st.top()=='{') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }
};