#include <iostream>
//#include "ArrayList.cpp"
#include "LinkedList.cpp"
using namespace std;

//printing function for List
void printList(List<int> &list)
{
    int prevPos = list.curPos();
    int j = prevPos;
    list.moveToStart();
    for (int i = 0; i < list.length(); i++, j--)
    {
        if (!j)
        {
            cout << "| ";
        }
        cout << list.getValue() << " ";
        list.next();
    }
    if (!j)
    {
        cout << "| ";
    }
    list.moveToPos(prevPos);
    cout << "\n";
}

int main()
{
    int k, x;
    cin >> k >> x;
    //ArrayList<int> list(x);
    LinkedList<int> list(x);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        list.append(a);
    }
    printList(list);
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
            list.clear();
            cout << "-1\n";
            break;
        case 2:
            list.insert(p);
            cout << "-1\n";
            break;
        case 3:
            list.append(p);
            cout << "-1\n";
            break;
        case 4:
            cout << (list.remove()) << "\n";
            break;
        case 5:
            list.moveToStart();
            cout << "-1\n";
            break;
        case 6:
            list.moveToEnd();
            cout << "-1\n";
            break;
        case 7:
            list.prev();
            cout << "-1\n";
            break;
        case 8:
            list.next();
            cout << "-1\n";
            break;
        case 9:
            cout << "Length: " << list.length() << "\n";
            break;
        case 10:
            cout << "Current Position: " << list.curPos() << "\n";
            break;
        case 11:
            list.moveToPos(p);
            cout << "-1\n";
            break;
        case 12:
            cout << "Value: " << list.getValue() << "\n";
            break;
        case 13:
            cout << "Search Index: " << list.Search(p) << "\n";
            break;
        default:
            break;
        }
        printList(list);
    }
    return 0;
}