from abc import ABC, abstractmethod

class List(ABC):
    """
    Things to keep in mind:
    1| can't call getValue(), currPos(), moveToPos() for an empty list.
    2| inserting or appending to an empty list automatically make the first element the current element by increasing size.
    3| if the current position points to last element and it is removed then current position will shift back to point to the last element.
    4| otherwise after removal of current element, current position will point to next element. 
    5| current position can not point to None 
    """

    @abstractmethod
    def clear(self):
        pass
    @abstractmethod
    def insert(self, item):
        pass
    @abstractmethod
    def append(self, item):
        pass
    @abstractmethod
    def remove(self):
        pass
    @abstractmethod
    def moveToStart(self):
        pass
    @abstractmethod
    def moveToEnd(self):
        pass
    @abstractmethod
    def prev(self):
        pass
    @abstractmethod
    def next(self):
        pass
    @abstractmethod
    def length(self):
        pass
    @abstractmethod
    def currPos(self):
        pass
    @abstractmethod
    def moveToPos(self, pos):
        pass
    @abstractmethod
    def getValue(self):
        pass
    @abstractmethod
    def Search(self, item):
        pass
