from LinkedList import LinkedList
from ArrayList import ArrayList

def printList(bist):
    prevPos = bist.currPos()
    barPos = prevPos
    bist.moveToStart()
    for _ in range(bist.length()):
        if barPos == 0:
            print('|', end=' ')
        barPos -= 1
        print(bist.getValue(), end=' ')
        bist.next()
    if barPos == 0:
        print('|', end=' ')
    print()
    bist.moveToPos(prevPos)

def main():
    k,x = map(int, input().strip().split())
    bist = ArrayList()
    #bist = LinkedList()
    for value in list(map(int, input().strip().split())):
        bist.append(value)
    printList(bist)
    while True:
        q, p = map(int, input().strip().split())
        if q == 0:
            break
        if q == 1:
            bist.clear()
            print('-1')
        elif q == 2:
            bist.insert(p)
            print('-1')
        elif q == 3:
            bist.append(p)
            print('-1')
        elif q == 4:
            print(bist.remove())
        elif q == 5:
            bist.moveToStart()
            print('-1')
        elif q == 6:
            bist.moveToEnd()
            print('-1')
        elif q == 7:
            bist.prev()
            print('-1')
        elif q == 8:
            bist.next()
            print('-1')
        elif q == 9:
            print(bist.length())
        elif q == 10:
            print(bist.currPos())
        elif q == 11:
            bist.moveToPos(p)
            print('-1')
        elif q == 12:
            print(bist.getValue())
        elif q == 13:
            print(bist.Search(p))
        printList(bist)


# main()