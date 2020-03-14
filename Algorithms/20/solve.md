## 思路

使用栈进行括号匹配即可.

### C++

```c++
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
```

### Java

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        int len=s.length();
        for(int i=0;i<len;++i){
            char ch=s.charAt(i);
            if(ch=='(' || ch=='[' || ch=='{') st.push(ch);
            else{
                if(ch==')'){
                    if(!st.empty() && st.peek()=='(') st.pop();
                    else return false;
                }
                else if(ch==']'){
                    if(!st.empty() && st.peek()=='[') st.pop();
                    else return false;
                }
                else{
                    if(!st.empty() && st.peek()=='{') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }
}
```

### Python

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        for ch in s:
            if ch=='(' or ch=='[' or ch=='{':
                stack.append(ch)
            elif ch==')':
                if len(stack)>0 and stack[-1]=='(':
                    stack.pop()
                else:
                    return False
            elif ch==']':
                if len(stack)>0 and stack[-1]=='[':
                    stack.pop()
                else:
                    return False
            else:
                if len(stack)>0 and stack[-1]=='{':
                    stack.pop()
                else:
                    return False
        return len(stack)==0
```

