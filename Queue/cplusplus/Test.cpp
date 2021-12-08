#include <iostream>
#include "LinkedQueue.h"
#include "ArrayQueue.h"
using namespace std;

template <class T>
void printQueue(Queue<T> &qu)
{
    ArrayQueue<T> copyQ;
    cout << "<";
    while (qu.length() > 0)
    {
        T cur = qu.dequeue();
        copyQ.enqueue(cur);
        cout << cur << (qu.length() == 0 ? "" : " ");
    }
    cout << ">\n";
    while (copyQ.length() > 0)
    {
        qu.enqueue(copyQ.dequeue());
    }
}

int main()
{

    int k;
    cin >> k;
    ArrayQueue<int> qu;
    // LinkedQueue<int> qu;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        qu.enqueue(a);
    }
    printQueue(qu);
    while (77)
    {
        int q, p;
        cin >> q >> p;
        if (!q)
        {
            break;
        }
        switch (q)
        {
        case 1:
        {
            qu.clear();
            printQueue(qu);
            cout << "-1\n";
            break;
        }
        case 2:
        {
            qu.enqueue(p);
            printQueue(qu);
            cout << "-1\n";
            break;
        }
        case 3:
        {
            int temp = qu.dequeue();
            printQueue(qu);
            cout << temp << "\n";
            break;
        }
        case 4:
        {
            int temp = qu.length();
            printQueue(qu);
            cout << temp << '\n';
            break;
        }
        case 5:
        {
            int temp = qu.frontValue();
            printQueue(qu);
            cout << temp << "\n";
            break;
        }
        case 6:
        {
            int temp = qu.rearValue();
            printQueue(qu);
            cout << temp << "\n";
            break;
        }
        case 7:
        {
            int temp = qu.leaveQueue();
            printQueue(qu);
            cout << temp << "\n";
            break;
        }
        default:
            break;
        }
    }
    return 0;
}