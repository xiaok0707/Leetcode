class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<(int)s.length();++i){
            if(s[i]=='(') st.push(i);
            else{
                int x=st.top();
                st.pop();
                if(st.empty()) st.push(i);
                else ans=max(ans,i-st.top());
            }
        }
        return ans;
    }
};