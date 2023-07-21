from LinkedQueue import LinkedQueue
from ArrayQueue import ArrayQueue


def main():
    n = int(input().strip())
    booth1 = LinkedQueue()
    booth2 = LinkedQueue()
    booth1_clock = 0
    booth2_clock = 0
    for _ in range(n):
        t, s = map(int, input().strip().split()[:2])
        #print(f'new input taken t: {t} s: {s}')
        #equalizing booth clocks with the input time
        while (booth1.length() > 0 and booth1_clock <= t) or (booth2.length() > 0 and booth2_clock <= t):
            if booth1.length() == 0:
                booth2.dequeue()
                if booth2.length() > 0:
                    booth2_clock += booth2.frontValue()
                    #print(f'front starts service at 2, finish at: {booth2_clock}')
            elif booth2.length() == 0:
                booth1.dequeue()
                if booth1.length() > 0:
                    booth1_clock += booth1.frontValue()
                    #print(f'front starts service at 1, finish at: {booth1_clock}')
            elif booth1_clock <= booth2_clock:
                booth1.dequeue()
                if booth1.length() > 0:
                    booth1_clock += booth1.frontValue()
                    #print(f'front starts service at 1, finish at: {booth1_clock}')
                #queue swithcing
                if (booth2.length() - booth1.length() >= 2) and (booth1_clock != t):
                    booth1.enqueue(booth2.leaveQueue())
                    if booth1.length() == 1:
                        booth1_clock += booth1.frontValue()
                    #print(f'last switched to 1') 
            else:
                booth2.dequeue()
                if booth2.length() > 0:
                    booth2_clock += booth2.frontValue()
                    #print(f'front starts service at 2, finish at: {booth2_clock}')
                #queue swithcing
                if (booth1.length() - booth2.length() >= 2) and (booth2_clock != t):
                    booth2.enqueue(booth1.leaveQueue())
                    if booth2.length() == 1:
                        booth2_clock += booth2.frontValue()
                    #print(f'last switched to 2') 
        #new customer enqueueing
        if booth1.length() <= booth2.length():
            booth1.enqueue(s)
            #print(f'new customer at 1')
            if booth1.length() == 1:
                booth1_clock = t + booth1.frontValue()
                #print(f'front starts service at 1, finish at: {booth1_clock}')
        else:
            booth2.enqueue(s)
            #print(f'new customer at 2')
            if booth2.length() == 1:
                booth2_clock = t + booth2.frontValue()
                #print(f'front starts service at 2, finish at: {booth2_clock}')

    
    while (booth1.length() > 1) or (booth2.length() > 1):
        if booth1_clock <= booth2_clock:
            booth1.dequeue()
            if booth1.length() > 0:
                booth1_clock += booth1.frontValue()
                #print(f'front starts service at 1, finish at: {booth1_clock}')
            #queue swithcing
            if (booth2.length() - booth1.length() >= 2) :
                booth1.enqueue(booth2.leaveQueue())
                booth1_clock += booth1.frontValue()
                #print(f'last switched to 1') 
        else:
            booth2.dequeue()
            if booth2.length() > 0:
                booth2_clock += booth2.frontValue()
                #print(f'front starts service at 2, finish at: {booth2_clock}')
            #queue swithcing
            if (booth1.length() - booth2.length() >= 2):
                booth2.enqueue(booth1.leaveQueue())
                booth2_clock += booth2.frontValue()
                #print(f'last switched to 2') 
    while booth1.length() > 0:
        booth1.dequeue()
    while booth2.length() > 0:
        booth2.dequeue()
    print(f'Booth 1 finishes service at t = {booth1_clock}\nBooth 2 finishes service at t = {booth2_clock}')

main()
