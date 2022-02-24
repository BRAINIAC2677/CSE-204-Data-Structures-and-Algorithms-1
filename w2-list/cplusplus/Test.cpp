#include <iostream>
#include "ArrayList.cpp"
//#include "LinkedList.cpp"
using namespace std;

//printing function for List
template <class E>
void printList(List<E> &list)
{
    if (list.length() == 0)
    {
        cout << "<>\n";
    }
    else
    {
        int prevPos = list.currPos();
        int j = prevPos;
        list.moveToStart();
        cout << "<";
        for (int i = 0; i < list.length(); i++, j--)
        {
            if (!j)
            {
                cout << "| ";
            }
            cout << list.getValue() << " ";
            list.next();
        }
        cout << ">\n";
        list.moveToPos(prevPos);
    }
}

int main()
{
    int k, x;
    cin >> k >> x;
    ArrayList<int> bist(x);
    //LinkedList<int> bist;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        bist.append(a);
    }
    printList(bist);
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
            bist.clear();
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 2:
        {
            bist.insert(p);
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 3:
        {
            bist.append(p);
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 4:
        {
            int removed = bist.remove();
            printList(bist);
            cout << removed << "\n";
            break;
        }
        case 5:
        {
            bist.moveToStart();
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 6:
        {
            bist.moveToEnd();
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 7:
        {
            bist.prev();
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 8:
        {
            bist.next();
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 9:
        {
            int l = bist.length();
            printList(bist);
            cout << l << "\n";
            break;
        }
        case 10:
        {
            int pos = bist.currPos();
            printList(bist);
            cout << pos << "\n";
            break;
        }
        case 11:
        {
            bist.moveToPos(p);
            printList(bist);
            cout << "-1\n";
            break;
        }
        case 12:
        {
            int val = bist.getValue();
            printList(bist);
            cout << val << "\n";
            break;
        }
        case 13:
        {
            int index = bist.Search(p);
            printList(bist);
            cout << index << "\n";
            break;
        }
        default:
            break;
        }
    }
    return 0;
}