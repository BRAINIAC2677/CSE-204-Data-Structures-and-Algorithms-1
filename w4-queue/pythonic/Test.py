from LinkedQueue import LinkedQueue
from ArrayQueue import ArrayQueue

def printQueue(queue):
    copyQ = LinkedQueue()
    print('<',end='')
    while queue.length() > 0:
        cur = queue.dequeue()
        copyQ.enqueue(cur)
        print(cur, end="" if queue.length() == 0 else " ")
    print(">")
    while copyQ.length() > 0:
        queue.enqueue(copyQ.dequeue())


def main():
    k = int(input().strip())
    #queue = LinkedQueue()
    lis = [None]*20
    queue = ArrayQueue(lis)
    for value in list(map(int, input().strip().split()[:k])):
        queue.enqueue(value)
    printQueue(queue)
    while True:
        q, p = map(int, input().strip().split()[:2])
        if q == 0:
            break
        elif q == 1:
            queue.clear()
            printQueue(queue)
            print('-1')
        elif q == 2:
            queue.enqueue(p)
            printQueue(queue)
            print('-1')
        elif q == 3:
            temp = queue.dequeue()
            printQueue(queue)
            print(temp)
        elif q == 4:
            temp = queue.length()
            printQueue(queue)
            print(temp)
        elif q == 5:
            temp = queue.frontValue()
            printQueue(queue)
            print(temp)
        elif q == 6:
            temp = queue.rearValue()
            printQueue(queue)
            print(temp)
        elif q == 7:
            temp = queue.leaveQueue()
            printQueue(queue)
            print(temp)

main()
    