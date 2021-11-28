#include <iostream>
using namespace std;
#include "LinkedStack.cpp"

int main()
{
    LinkedStack<int> a;
    cout << a.length() << "\n";
    for (int i = 0; i < 3; i++)
    {
        a.push(i);
    }
    cout << a.top() << "\n";
    cout << a.length() << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << a.pop() << "\n";
    }
    LinkedStack<char> b;
    b.push('a');
    cout << b.top() << "\n";
    b.clear();
    b.top();
    return 0;
}