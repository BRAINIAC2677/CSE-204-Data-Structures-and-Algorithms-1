from Stack import Stack
from CustomExceptions import EmptyStackException

class ArrayStack(Stack):
    def __init__(self, capacity=1000):
        self.__capacity = capacity
        self.__container = [None]*self.__capacity
        self.__top = -1
    
    def __reallocate(self):
        self.__capacity *= 2
        tempContainer = self.__container
        self.__container = [None]*self.__capacity
        for i in range(len(tempContainer)):
            self.__container[i] = tempContainer[i]
    
    def clear(self):
        self.__top = -1

    def length(self):
        return self.__top+1

    def push(self, value):
        if self.__top + 1 == self.__capacity:
            self.__reallocate()
        self.__top += 1
        self.__container[self.__top] = value

    def pop(self):
        if self.__top == -1:
            raise EmptyStackException()
        else:
            topValue = self.__container[self.__top]
            self.__top -= 1
            return topValue
        
    def top(self):
        if self.__top == -1:
            raise EmptyStackException()
        else:
            return self.__container[self.__top]

