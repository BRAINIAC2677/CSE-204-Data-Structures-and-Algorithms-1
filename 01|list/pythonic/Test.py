from LinkedList import LinkedList
from ArrayList import ArrayList

def printList(bist):
    if bist.length() == 0:
        print("<>")
    else:
        prevPos = bist.currPos()
        barPos = prevPos
        bist.moveToStart()
        print('<', end='')
        for i in range(bist.length()):
            if barPos == 0:
                print('|', end=' ')
            barPos -= 1
            print(bist.getValue(), end='' if i == bist.length() - 1 else ' ')
            bist.next()
        print('>')
        bist.moveToPos(prevPos)

def main():
    k,x = map(int, input().strip().split())
    bist = ArrayList(x)
    #bist = LinkedList()
    for value in list(map(int, input().strip().split()[:k])):
        bist.append(value)
    printList(bist)
    while True:
        q, p = map(int, input().strip().split())
        if q == 0:
            break
        if q == 1:
            bist.clear()
            printList(bist)
            print('-1')
        elif q == 2:
            bist.insert(p)
            printList(bist)
            print('-1')
        elif q == 3:
            bist.append(p)
            printList(bist)
            print('-1')
        elif q == 4:
            removed = bist.remove()
            printList(bist)
            print(removed)
        elif q == 5:
            bist.moveToStart()
            printList(bist)
            print('-1')
        elif q == 6:
            bist.moveToEnd()
            printList(bist)
            print('-1')
        elif q == 7:
            bist.prev()
            printList(bist)
            print('-1')
        elif q == 8:
            bist.next()
            printList(bist)
            print('-1')
        elif q == 9:
            l = bist.length()
            printList(bist)
            print(l)
        elif q == 10:
            pos = bist.currPos()
            printList(bist)
            print(pos)
        elif q == 11:
            bist.moveToPos(p)
            printList(bist)
            print('-1')
        elif q == 12:
            val = bist.getValue()
            printList(bist)
            print(val)
        elif q == 13:
            index = bist.Search(p)
            printList(bist)
            print(index)


main()
