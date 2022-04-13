from abc import ABC, abstractmethod

class Stack(ABC):
    @abstractmethod
    def clear(self):
        pass
    @abstractmethod
    def length(self):
        pass
    @abstractmethod
    def push(self, value):
        pass
    @abstractmethod
    def pop(self):
        pass
    @abstractmethod
    def top(self):
        pass