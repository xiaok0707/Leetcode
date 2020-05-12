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
