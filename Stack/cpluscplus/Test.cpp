#include <iostream>
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"
using namespace std;

// printing function for stack
template <class E>
void printArrayStack(ArrayStack<E> &stk)
{
    ArrayStack<E> temp;
    while (stk.length() > 0)
    {
        temp.push(stk.pop());
    }
    cout << "<";
    while (temp.length() > 0)
    {
        cout << temp.top() << (temp.length() == 1 ? "" : " ");
        stk.push(temp.pop());
    }
    cout << ">\n";
}

template <class E>
void printArrayStack(LinkedStack<E> &stk)
{
    LinkedStack<E> temp;
    while (stk.length() > 0)
    {
        temp.push(stk.pop());
    }
    cout << "<";
    while (temp.length() > 0)
    {
        cout << temp.top() << (temp.length() == 1 ? "" : " ");
        stk.push(temp.pop());
    }
    cout << ">\n";
}

int main()
{
    int k;
    cin >> k;
    ArrayStack<int> stk;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        stk.push(a);
    }
    printArrayStack(stk);
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
            stk.clear();
            cout << "-1\n";
            break;
        }
        case 2:
        {
            stk.push(p);
            cout << "-1\n";
            break;
        }
        case 3:
        {
            cout << stk.pop() << "\n";
            break;
        }
        case 4:
        {
            cout << stk.length() << "\n";
            break;
        }
        case 5:
        {
            cout << stk.top() << "\n";
            break;
        }
        case 6:
        {
            stk.setDirection(p);
            cout << "-1\n";
            break;
        }
        default:
            break;
        }
        printArrayStack(stk);
    }
    return 0;
}