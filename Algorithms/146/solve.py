class DlinkedNode:
    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = dict()
        self.head = DlinkedNode()
        self.tail = DlinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            val = node.val
            del self.cache[key]
            self.delNode(node)

            node = DlinkedNode(key, val)
            self.cache[key] = node
            self.addTail(node)
            return val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            del self.cache[key]
            self.delNode(node)

            node = DlinkedNode(key, value)
            self.cache[key] = node
            self.addTail(node)
        else:
            if self.size == self.capacity:
                self.size -= 1
                node = self.head.next
                del self.cache[node.key]
                self.delNode(node)
            self.size += 1
            node = DlinkedNode(key, value)
            self.cache[key] = node
            self.addTail(node)

    def delNode(self, node: DlinkedNode):
        prev = node.prev
        next = node.next
        prev.next = next
        next.prev = prev
        del node

    def addTail(self, node: DlinkedNode):
        prev = self.tail.prev
        next = self.tail
        prev.next = node
        next.prev = node
        node.prev = prev
        node.next = next

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)