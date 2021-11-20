from List import List

class ArrayList(List):
    def __init(self, maxSize):
        self.curr = 0
        self.size = 0
        self.maxSize = maxSize
        self.listArray = [None]*self.maxSize

    def __increaseSize(self):
        self.listArray = self.listArray + [None]*self.maxSize
        self.maxSize *= 2

    def __init__(self, arg = None):
        assert arg is None or isinstance(arg, int) or isinstance(arg, List),"Invalid Initialization"
        if isinstance(arg, List):
            self.curr = arg.currPos()
            self.size = arg.length()
            self.maxSize = self.size
            self.listArray = [None]*self.maxSize
            arg.moveToStart()
            for i in range(self.size):
                self.listArray[i] = arg.getValue()
                arg.next()
            arg.moveToPos(self.curr)
        elif isinstance(arg, int):
            assert arg > 0, "invalid initialization"
            self.__init(arg)
        else:
            self.__init(1000) #1000 default maxSize
    
    def clear(self):
        self.__init(1000)

    def insert(self, item):
        if self.size == self.maxSize:
            self.__increaseSize()
        for i in range(self.size, 0, -1):
            self.listArray[i] = self.listArray[i-1]
            if self.curr == i-1:
                break
        self.listArray[self.curr] = item
        self.size += 1
    
    def append(self, item):
        if self.size == self.maxSize:
            self.__increaseSize()
        self.listArray[self.size] = item
        self.size += 1

    def remove(self):
        assert self.size > 0, "empty list"
        temp = self.listArray[self.curr]
        for i in range(self.curr, self.size - 1):
            self.listArray[i] = self.listArray[i+1]
        self.size -= 1
        return temp

    def moveToStart(self):
        self.curr = 0

    def moveToEnd(self):
        self.curr = self.size

    def prev(self):
        self.curr = 0 if self.curr == 0 else self.curr - 1
    
    def next(self):
        self.curr = self.curr if self.curr == self.size else self.curr + 1

    def length(self):
        return self.size
    
    def currPos(self):
        return self.curr
    
    def moveToPos(self, pos):
        assert (pos >= 0 and pos <= self.size), "invalid position"
        self.curr = pos

    def getValue(self):
        assert self.curr < self.size, "End of the list"
        return self.listArray[self.curr]
    
    def Search(self, item):
        for i in range(self.size):
            if self.listArray[i] == item:
                return i
        return -1

    


