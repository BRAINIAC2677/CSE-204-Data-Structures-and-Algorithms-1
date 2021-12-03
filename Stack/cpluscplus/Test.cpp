#include <iostream>
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"
using namespace std;

// printing function for stack
template <class E>
void printStack(Stack<E> &stk)
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
    // LinkedStack<int> stk;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        stk.push(a);
    }
    printStack(stk);
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
            printStack(stk);
            cout << "-1\n";
            break;
        }
        case 2:
        {
            stk.push(p);
            printStack(stk);
            cout << "-1\n";
            break;
        }
        case 3:
        {
            int temp = stk.pop();
            printStack(stk);
            cout << temp << "\n";
            break;
        }
        case 4:
        {
            int temp = stk.length();
            printStack(stk);
            cout << temp << '\n';
            break;
        }
        case 5:
        {
            int temp = stk.top();
            printStack(stk);
            cout << temp << "\n";
            break;
        }
        case 6:
        {
            stk.setDirection(p);
            printStack(stk);
            cout << "-1\n";
            break;
        }
        default:
            break;
        }
    }
    return 0;
}