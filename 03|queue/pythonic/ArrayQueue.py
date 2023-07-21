from Queue import Queue

class ArrayQueue(Queue):
    def __myInit(self, maxCapacity):
        self.front = 1
        self.rear = 0
        self.maxCapacity = maxCapacity
        self.container = [None for i in range(self.maxCapacity)]
    
    def __reallocate(self):
        self.container = self.container + [None for i in range(self.maxCapacity)]
        self.maxCapacity *= 2 

    def __init__(self, arg = None):
        if arg is None:
            self.__myInit(1000)  
        elif isinstance(arg, int):
            self.__myInit(arg)
        elif isinstance(arg, list):
            self.front = 1
            self.rear = 0
            self.maxCapacity = len(arg)
            self.container = arg
        else:
            assert "invalid constructor"
    
    def clear(self):
        self.front = 1
        self.rear = 0

    def enqueue(self, item):
        if (self.rear + 2)%self.maxCapacity == self.front:
            self.__reallocate()
        self.rear = (self.rear + 1)%self.maxCapacity
        self.container[self.rear] = item

    def dequeue(self):
        assert self.length() > 0, "Dequeue invalid on empty queue"
        ret = self.container[self.front]
        self.front = (self.front + 1)%self.maxCapacity
        return ret

    def length(self):
        return (self.rear - self.front + 1 + self.maxCapacity)%self.maxCapacity

    def frontValue(self):
        assert self.length() > 0, "frontValue invalid on empty queue"
        return self.container[self.front]

    def rearValue(self):
        assert self.length() > 0, "rearValue invalid on empty queue"
        return self.container[self.rear]

    def leaveQueue(self):
        assert self.length() > 0, "leaveQueue invalid on empty queue"
        ret = self.container[self.rear]
        self.rear = (self.rear - 1 + self.maxCapacity)%self.maxCapacity
        return ret
