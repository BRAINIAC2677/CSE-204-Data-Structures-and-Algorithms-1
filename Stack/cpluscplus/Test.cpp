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
    int *p = new int[100];
    ArrayStack<int> a(p, 100), b(p, 100, -1);
    a.push(5);
    a.push(7);
    b.push(999);
    printArrayStack(a);
    printArrayStack(b);
    return 0;
}