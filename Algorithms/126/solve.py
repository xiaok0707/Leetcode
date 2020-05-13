from collections import defaultdict

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList: return []
        if beginWord not in wordList: wordList.append(beginWord)

        L=len(beginWord)
        g=defaultdict(list)
        for word in wordList:
            for i in range(L):
                g[word[:i]+'*'+word[i+1:]].append(word)

        done=set(beginWord)
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