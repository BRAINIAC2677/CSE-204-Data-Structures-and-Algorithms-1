from Stack import Stack
from CustomExceptions import EmptyStackException

class Node:
    def __init__(self, element, next=None):
        self.__element = element
        self.__next = next

    def getNext(self):
        return self.__next
    
    def getElement(self):
        return self.__element

    def setNext(self, next):
        self.__next = next
    
    def setElement(self, element):
        self.__element = element

class ListStack(Stack):
    def __init__(self):
        self.__size = 0
        self.__top = None

    def clear(self):
        self.__init__();

    def length(self):
        return self.__size

    def push(self, value):
        newNode = Node(value, self.__top)
        self.__top = newNode
        self.__size += 1

    def pop(self):
        if self.__top is None:
            raise EmptyStackException()
        else:
            topValue = self.__top.getElement()
            self.__top = self.__top.getNext()
            self.__size -= 1
            return topValue

    def top(self):
        if self.__top is None:
            raise EmptyStackException()
        else:
            return self.__top.getElement()

