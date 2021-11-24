from List import List

class ArrayList(List):
    #private helper methods
    def __myInit(self, chunkSize = 100000):
        assert self.chunkSize > 0, "invalid chunksize"
        self.curr = 0
        self.size = 0
        self.chunkSize = chunkSize
        self.capacity = chunkSize
        self.listArray = [None]*self.capacity

    def __increaseSize(self):
        self.listArray = self.listArray + [None]*self.chunkSize
        self.capacity += self.chunkSize

    #works as constructor
    def __init__(self, *args):
        """valid 4 initializers:
        1| ArrayList()
        2| ArrayList(int) 
        3| ArrayList(List)
        4| ArrayList(int, List)
        """
        if len(args) == 0:
            self.__myInit()
        elif len(args) == 1 and isinstance(args[0], int):
            self.__myInit(args[0])
        elif len(args) == 1 and isinstance(args[0], List):
            if args[0].length() == 0:
                self.__myInit()
            else:
                self.curr = args[0].currPos()
                self.size = args[0].length()
                self.chunkSize = self.size
                self.listArray = [None]*self.chunkSize
                args[0].moveToStart()
                for i in range(self.size):
                    self.listArray[i] = args[0].getValue()
                    args[0].next()
                if args[0].length() > 0:
                    args[0].moveToPos(self.curr)
        elif len(args) == 2 and isinstance(args[0], int) and isinstance(args[1],List):
            assert args[0] >= args[1].length(), "initial capacity can not be less than the length of the initialized list"
            if args[1].length() == 0:
                self.__myInit(args[0])
            else:
                self.curr = args[1].currPos()
                self.size = args[1].length()
                self.chunkSize = args[0]
                self.listArray = [None]*self.chunkSize
                args[1].moveToStart()
                for i in range(self.size):
                    self.listArray[i] = args[1].getValue()
                    args[1].next()
                if args[1].length() > 0:
                    args[1].moveToPos(self.curr)
        else:
            raise AssertionError("Invalid Initialization")
    
    def clear(self):
        self.__myInit(self.chunkSize)

    def insert(self, item):
        if self.size == self.capacity:
            self.__increaseSize()
        for i in range(self.size, 0, -1):
            self.listArray[i] = self.listArray[i-1]
            if self.curr == i-1:
                break
        self.listArray[self.curr] = item
        self.size += 1
    
    def append(self, item):
        if self.size == self.capacity:
            self.__increaseSize()
        self.listArray[self.size] = item
        self.size += 1

    def remove(self):
        """remove the current element and points to the next element. 
        But if the last element is removed the curr moves to the prev element.
        Returns:
            [list element type]: [removed item]
        """
        assert self.size > 0, "can not remove from an empty list"
        temp = self.listArray[self.curr]
        for i in range(self.curr, self.size - 1):
            self.listArray[i] = self.listArray[i+1]
        self.size -= 1
        if self.curr >= self.size:
            self.curr = self.size - 1 if self.size != 0 else 0
        return temp

    def moveToStart(self):
        self.curr = 0

    def moveToEnd(self):
        self.curr = self.size - 1 if self.size > 0 else 0

    def prev(self):
        self.curr = 0 if self.curr == 0 else self.curr - 1
    
    def next(self):
        self.curr = self.curr if self.curr >= self.size - 1 else self.curr + 1

    def length(self):
        return self.size
    
    def currPos(self):
        assert self.size > 0, "No current element in an empty list"
        return self.curr
    
    def moveToPos(self, pos):
        #moving to a position in an empty list is an invalid opeartion
        assert (self.size >= 0) and (pos < self.size), "invalid index"
        self.curr = pos

    def getValue(self):
        assert self.size > 0, "No current element in an empty list"
        return self.listArray[self.curr]
    
    def Search(self, item):
        for i in range(self.size):
            if self.listArray[i] == item:
                return i
        return -1

    


