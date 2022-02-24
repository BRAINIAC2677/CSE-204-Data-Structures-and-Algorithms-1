from Queue import Queue

class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next
    def getData(self):
        return self.data
    def getNext(self):
        return self.next
    def setData(self, newData):
        self.data = newData
    def setNext(self, newNext):
        self.next = newNext

class LinkedQueue(Queue):
    def __myInit(self):
        self.front = Node()
        self.rear = self.front
        self.size = 0

    def __init__(self):
        self.__myInit()

    def clear(self):
        self.__myInit()

    def enqueue(self, item):
        self.size += 1
        newNode = Node(item, None)
        self.rear.setNext(newNode)
        self.rear = newNode

    def dequeue(self):
        assert self.size > 0, "Dequeue invalid on empty queue"
        self.size -= 1
        ret = self.front.getNext().getData()
        self.front = self.front.getNext()
        return ret

    def length(self):
        return self.size

    def frontValue(self):
        assert self.size > 0, "frontValue invalid on empty queue"
        return self.front.getNext().getData()

    def rearValue(self):
        assert self.size > 0, "rearValue invalid on empty queue"
        return self.rear.getData()

    def leaveQueue(self):
        assert self.size > 0, "leaveQueue invalid on empty queue"
        self.size -= 1
        ret = self.rear.getData()
        temp = self.front
        while temp.getNext() is not  self.rear:
            temp = temp.getNext()
        self.rear = temp
        return ret