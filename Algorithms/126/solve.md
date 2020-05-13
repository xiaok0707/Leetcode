## 思路

BFS广搜，关键在于建图时的优化，将每一个具体的单词抽象成图中的结点.

最重要的步骤是找出相邻的节点，也就是只差一个字母的两个单词。为了快速的找到这些相邻节点，我们对给定的 wordList 做一个预处理，将单词中的某个字母用 * 代替。

![Word_Ladder_2.png](https://pic.leetcode-cn.com/7212249f3e224d9d5ccbc292e902e48b572f965236378e034d8e03924404cba2-Word_Ladder_2.png)

这个预处理构造了一个通用状态到普通单词的映射。例如在广搜时我们需要访问 `Dug` 的所有邻接点，我们可以先生成 `Dug` 的所有通用状态：

1. `Dug => *ug`
2. `Dug => D*g`
3. `Dug => Du*`

然后依次找到这些通用状态对应哪些普通单词，也就找出了图中的相邻接点.

这个题还要求两点间的所有最短路径，在BFS的过程中要记录当前路径，为了防止结点的重复遍历，需要记录已访问过的结点，但此题和普通的BFS不同，如果在访问过当前结点后直接将其标记为已访问结点，不再让其在后续过程中被访问，是有可能忽略掉一些答案的，比如 beginWord='abc', endWord='acd', wordList=['abc','abd','acc','acd']，转换关系如下。

![1.png](https://i.loli.net/2020/05/13/ZtUoTQYD6vSIOJV.png)

很明显有两条最短路径，如果第一次遇到终点 'acd'，就将其标记为已访问，那么只能记录其中的一条。需要对BFS做一些修改，**每次遍历当前层的所有结点，向下一层扩展，当前层所有结点都扩展结束之后，再将刚才新访问到的结点标记为已访问的状态.**

### Python

```python
from collections import defaultdict

class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        if endWord not in wordList: return []
        if beginWord not in wordList: wordList.append(beginWord)

        L=len(beginWord)
        g=defaultdict(list)
        for word in wordList:
            for i in range(L):
                g[word[:i]+'*'+word[i+1:]].append(word)

        done=set([beginWord])
        que=[[beginWord,]]
        res=[]
        flag=False

        while que and not flag:
            sz=len(que)
            curdone=set()
            for i in range(sz):
                curlist=que.pop(0)
                curword=curlist[-1]
                for j in range(L):
                    midword=curword[:j]+'*'+curword[j+1:]
                    for newword in g[midword]:
                        if newword in done: continue
                        curlist.append(newword)
                        que.append(curlist[:])
                        if newword==endWord:
                            flag=True
                            res.append(curlist[:])
                        curlist.pop()
                        curdone.add(newword)
            done.update(curdone)

        return res
```

