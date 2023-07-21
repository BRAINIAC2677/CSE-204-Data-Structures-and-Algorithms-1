from abc import ABC, abstractmethod


class Queue(ABC):
    @abstractmethod
    def clear(self):
        pass
    @abstractmethod 
    def enqueue(self,item):
        pass
    @abstractmethod
    def dequeue(self):
        pass
    @abstractmethod
    def length(self):
        pass
    @abstractmethod
    def frontValue(self):
        pass
    @abstractmethod
    def rearValue(self):
        pass
    @abstractmethod
    def leaveQueue(self):
        pass