#include <iostream>
using namespace std;
#include "ArrayStack.cpp"

int main()
{
    ArrayStack<int> a(10, -1);
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
    return 0;
}