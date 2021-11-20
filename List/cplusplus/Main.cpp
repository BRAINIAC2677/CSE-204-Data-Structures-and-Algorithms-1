#include <iostream>
#include "ArrayList.cpp"
//#include "LinkedList.cpp"
using namespace std;

//printing function for List
template <class E>
void printList(List<E> &list)
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
    ArrayList<int> a;
    a.append(2);
    ArrayList<int> b(a);
    a.clear();
    printList(a);
    printList(b);
    return 0;
}