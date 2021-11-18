#include <iostream>
#include "ArrayList.cpp"
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
    ArrayList<int> aList(x);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        aList.append(a);
    }
    printList(aList);
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
            aList.clear();
            cout << "-1\n";
            break;
        case 2:
            aList.insert(p);
            cout << "-1\n";
            break;
        case 3:
            aList.append(p);
            cout << "-1\n";
            break;
        case 4:
            cout << (aList.remove()) << "\n";
            break;
        case 5:
            aList.moveToStart();
            cout << "-1\n";
            break;
        case 6:
            aList.moveToEnd();
            cout << "-1\n";
            break;
        case 7:
            aList.prev();
            cout << "-1\n";
            break;
        case 8:
            aList.next();
            cout << "-1\n";
            break;
        case 9:
            cout << "Length: " << aList.length() << "\n";
            break;
        case 10:
            cout << "Current Position: " << aList.curPos() << "\n";
            break;
        case 11:
            aList.moveToPos(p);
            cout << "-1\n";
            break;
        case 12:
            cout << "Value: " << aList.getValue() << "\n";
            break;
        case 13:
            cout << "Search Index: " << aList.Search(p) << "\n";
            break;
        default:
            break;
        }
        printList(aList);
    }
    return 0;
}