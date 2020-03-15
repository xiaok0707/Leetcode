## 思路

### 搜索

状态为当前字符串，当前左括号数量，当前右括号数量. 

为了保持合法性，在状态转移时

如果左括号数量<n，则可以在末尾增加一个左括号.

如果右括号数量<左括号数量 且 右括号数量<n，则可以在末尾增加一个右括号.

当左括号数量+右括号数量=2n，说明找到了一组解.

### C++

```c++
class Solution {
public:
    int n;
    string str;
    vector<string> ans;

    void dfs(int a,int b){
        if(a+b==2*n){
            ans.push_back(str);
            return;
        }
        if(a<n){
            str+='(';
            dfs(a+1,b);
            str.pop_back();
        }
        if(a>b && b<n){
            str+=')';
            dfs(a,b+1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        str="";
        ans.clear();
        dfs(0,0);
        return ans;
    }
};
```

### Java

```java
class Node {
    String str;
    int a,b;
    Node(){}
    Node(String str,int a,int b){
        this.str=str;
        this.a=a;
        this.b=b;
    }
}

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans=new LinkedList<>();
        Queue<Node> que=new LinkedList<>();
        que.offer(new Node("",0,0));
        while(!que.isEmpty()){
            Node x=que.poll();
            if(x.a+x.b==n*2)
                ans.add(x.str);
            if(x.a<n)
                que.offer(new Node(x.str+"(",x.a+1,x.b));
            if(x.b<x.a && x.b<n)
                que.offer(new Node(x.str+")",x.a,x.b+1));
        }
        return ans;
    }
}
```

### DP

令 $dp[i]$ 表示 $i$ 对括号能构成的合法串的数量，那么有如下递推公式.

$dp[i]=\sum_{k=0}^{i-1}dp[i-1-k]×dp[k]$

意思是，$i$ 对括号构成的串可以由 $i-1,i-2,i-3...$ 对括号构成的串（已知的解）构造出来.

可以考虑 $dp[i]$ 比 $dp[i-1]$ 多出来的那一对括号的位置，那么

长为 $i$ 的合法串= '(' + 长为 $i-1-k$ 的合法串 + ')' + 长为 $k$ 的合法串，$k$ 从 0 到 $i-1$

这个递推公式也是卡特兰数的递推式，因为这道题不是求数量，而是求出所有的合法串，所以 $dp[i]$ 要表示的其实是 $i$ 对括号能够成的所有合法串，是一个集合，python中用列表表示.

### Python

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp=[None for i in range(n+1)]
        dp[0]=['']
        for i in range(1,n+1):
            dp[i]=[]
            for k in range(i):
                for a in dp[i-1-k]:
                    for b in dp[k]:
                        dp[i].append('('+a+')'+b)
        return dp[n]
```

