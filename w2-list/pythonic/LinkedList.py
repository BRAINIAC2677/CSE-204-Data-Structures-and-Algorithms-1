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
    def __myInit(self):
        self.head = Node()
        self.tail = self.head
        self.curr = self.head #curr of empty list points to the head
        self.size = 0
        
    def __init__(self, arg = None):
        """
            valid 2 initializer:
            1| LinkedList()
            2| LinkedList(List)
        """
        assert arg is None or isinstance(arg, List), "Invalid Initialization"
        self.__myInit()
        if isinstance(arg, List) and arg.length() > 0:
            prevPos = arg.currPos()
            arg.moveToStart()
            for _ in range(arg.length()):
                self.append(arg.getValue())
                arg.next()
            arg.moveToPos(prevPos)

    def clear(self):
        self.__myInit()
    
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
        """remove the current element and points to the next element. 
        But if the last element is removed the curr moves to the prev element.
        Returns:
            [list element type]: [removed item]
        """
        assert self.size > 0, "can not remove from an empty list"
        self.size -= 1
        temp = self.curr.getNext()
        self.curr.setNext(temp.getNext())
        if temp.getNext() is None:
            self.tail = self.curr
            self.prev()
        return temp.getData()

    def moveToStart(self):
        self.curr = self.head

    def moveToEnd(self):
        while self.curr.getNext() is not self.tail:
            self.next()

    def prev(self):
        if self.curr is not self.head:
            temp = self.head
            while temp.getNext() != self.curr:
                temp = temp.getNext()
            self.curr = temp
    
    def next(self):
        if self.curr.getNext() is not None and self.curr.getNext().getNext() is not None:
            self.curr = self.curr.getNext()
    
    def length(self):
        return self.size

    def currPos(self):
        assert self.size > 0, "No current element in an empty list"
        index = 0
        temp = self.head
        while temp is not self.curr:
            temp = temp.getNext()
            index += 1
        return index
    
    def moveToPos(self, pos):
        #moving to a position in an empty list is an invalid opeartion
        assert (pos >= 0) and (pos < self.size), "invalid index"
        self.curr = self.head
        for _ in range(pos):
            self.curr = self.curr.getNext()

    def getValue(self):
        assert self.size > 0, "No current element in an empty list"
        return self.curr.getNext().getData()
    
    def Search(self, item):
        temp = self.head
        for i in range(self.size):
            if temp.getNext().getData() == item:
                return i
            temp = temp.getNext()
        return -1 
    