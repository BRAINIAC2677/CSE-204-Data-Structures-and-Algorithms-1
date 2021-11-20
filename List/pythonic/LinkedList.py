from List import List

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
    

class LinkedList(List):
    def __init__(self, arg = None):
        assert arg is None or isinstance(arg, List), "Invalid Initialization"
        self.head = Node()
        self.tail = self.head
        self.curr = self.head
        self.size = 0
        if isinstance(arg, List):
            prevPos = arg.currPos()
            arg.moveToStart()
            for i in range(arg.length()):
                self.append(arg.getValue())
                arg.next()
            arg.moveToPos(prevPos)

    def clear(self):
        self.head = Node()
        self.tail = self.head
        self.curr = self.head
        self.size = 0
    
    def insert(self, item):
        newNode = Node(item, self.curr.getNext())
        self.curr.setNext(newNode)
        self.size += 1
        if newNode.getNext() is None:
            self.tail = newNode

    def append(self, item):
        newNode = Node(item)
        self.tail.setNext(newNode)
        self.tail = newNode
        self.size += 1

    def remove(self):
        assert self.curr.getNext() is not None, "Cannot remove from an empty list"
        temp = self.curr.getNext()
        self.curr.setNext(temp.getNext())
        self.size -= 1
        if self.curr.getNext() is None:
            self.tail = self.curr
        return temp.getData()

    def moveToStart(self):
        self.curr = self.head

    def moveToEnd(self):
        self.curr = self.tail

    def prev(self):
        if self.curr is not self.head:
            temp = self.head
            while temp.getNext() != self.curr:
                temp = temp.getNext()
            self.curr = temp
    
    def next(self):
        if self.curr is not self.tail:
            self.curr = self.curr.getNext()
    
    def length(self):
        return self.size

    def currPos(self):
        index = 0
        temp = self.head
        while temp is not self.curr:
            temp = temp.getNext()
            index += 1
        return index
    
    def moveToPos(self, pos):
        self.curr = self.head
        for _ in range(pos):
            self.curr = self.curr.getNext()

    def getValue(self):
        assert self.curr.getNext() is not None,"End of the list"
        return self.curr.getNext().getData()
    
    def Search(self, item):
        temp = self.head
        for i in range(self.size):
            if temp.getNext().getData() == item:
                return i
            temp = temp.getNext()
        return -1 
    