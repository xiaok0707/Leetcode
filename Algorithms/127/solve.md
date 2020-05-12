## 思路

BFS广搜，关键在于建图时的优化，将每一个具体的单词抽象成图中的结点.

最重要的步骤是找出相邻的节点，也就是只差一个字母的两个单词。为了快速的找到这些相邻节点，我们对给定的 wordList 做一个预处理，将单词中的某个字母用 * 代替。

![Word_Ladder_2.png](https://pic.leetcode-cn.com/7212249f3e224d9d5ccbc292e902e48b572f965236378e034d8e03924404cba2-Word_Ladder_2.png)

这个预处理构造了一个通用状态到普通单词的映射。例如在广搜时我们需要访问 `Dug` 的所有邻接点，我们可以先生成 `Dug` 的所有通用状态：

1. `Dug => *ug`
2. `Dug => D*g`
3. `Dug => Du*`

然后依次找到这些通用状态对应哪些普通单词，也就找出了图中的相邻接点.

### Python

```python
from collections import defaultdict

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        if beginWord not in wordList: wordList.append(beginWord)

        L=len(beginWord)
        g=defaultdict(list)
        for word in wordList:
            for i in range(L):
                g[word[:i]+'*'+word[i+1:]].append(word)

        que=[(beginWord,1)]
        done=defaultdict(bool)
        while que:
            word,dist=que.pop(0)
            if done[word]: continue
            done[word]=True
            if word==endWord: return dist

            for i in range(L):
                midword=word[:i]+'*'+word[i+1:]
                for newword in g[midword]:
                    que.append((newword,dist+1))
                g[midword]=[] # 当前状态对应的所有字符串已经加入队列了，再次遇到这一状态就没必要继续进队列了
        return 0

```

