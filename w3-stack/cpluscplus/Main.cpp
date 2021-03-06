#include <iostream>
using namespace std;
#include "LinkedStack.cpp"
#include "ArrayStack.cpp"

int main()
{
    int n, x;
    cin >> n >> x;
    int a[x] = {0};
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    /*     LinkedStack<int> dirty, cleaned;
        LinkedStack<int> full_meal_friends; */
    int *p = new int[n * x];
    ArrayStack<int> dirty(p, n * x), cleaned(p, n * x, -1);
    ArrayStack<int> full_meal_friends;
    int washing_clock = 0;
    while (true)
    {
        int k, t, s;
        cin >> k >> t >> s;
        if (k == 0)
        {
            while (dirty.length() > 0)
            {

                washing_clock += (dirty.pop() - 1);
                cleaned.push(washing_clock++);
            }

            break;
        }
        while (washing_clock < t)
        {
            if (dirty.length() == 0)
            {
                washing_clock = t;
                break;
            }
            else
            {
                washing_clock += (dirty.pop() - 1);
                cleaned.push(washing_clock++);
            }
        }
        dirty.push(a[s - 1]);
        if (s == x)
        {
            full_meal_friends.push(k);
        }
    }
    cout << cleaned.top() << "\n";
    LinkedStack<int> temp;
    // ArrayStack<int> temp;
    while (cleaned.length() > 0)
    {
        temp.push(cleaned.pop());
    }
    while (temp.length() > 0)
    {
        cout << temp.pop();
        cout << (temp.length() > 0 ? "," : "\n");
    }
    cout << (full_meal_friends.length() == n ? "Y" : "N") << "\n";
    while (full_meal_friends.length() > 0)
    {
        cout << full_meal_friends.pop();
        cout << (full_meal_friends.length() > 0 ? "," : "\n");
    }
    delete[] p;
    return 0;
}