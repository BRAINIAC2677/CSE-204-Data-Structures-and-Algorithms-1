from abc import ABC, abstractmethod

class List(ABC):

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
