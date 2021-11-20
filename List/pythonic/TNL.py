from LinkedList import LinkedList
from ArrayList import ArrayList

def main():
    k = int(input())
    l = int(input())
    #bs = LinkedList()
    bs = ArrayList()
    for value in list(map(int, input().strip().split()[:l])):
        bs.append(value)
    m = int(input())
    #ts = LinkedList()
    ts = LinkedList()
    for value in list(map(int, input().strip().split()[:m])):
        ts.append(value)
    task = int(input())
    if task == 1:
        for i in range(k):
            print(i, end=('\n' if i == k-1 else ','))
        for i in range(k):
            temp = ',' if bs.Search(i) == -1 else i
            print(temp,end='')
            if temp != ',':
                print(end=('\n' if i == k-1 else ','))
        for i in range(k):
            temp = ',' if ts.Search(i) == -1 else i
            print(temp,end='')
            if temp != ',':
                print(end=('\n' if i == k-1 else ','))

main()