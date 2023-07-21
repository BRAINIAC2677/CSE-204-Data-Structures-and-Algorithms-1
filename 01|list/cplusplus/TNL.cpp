#include <iostream>
//#include "LinkedList.cpp"
#include "ArrayList.cpp"
using namespace std;

int main()
{
    int k, b, t;
    cin >> k >> b;
    //LinkedList<int> bs;
    ArrayList<int> bs(b);
    for (int i = 0; i < b; i++)
    {
        int st;
        cin >> st;
        bs.append(st);
    }
    cin >> t;
    //LinkedList<int> ts;
    ArrayList<int> ts(t);
    for (int i = 0; i < t; i++)
    {
        int st;
        cin >> st;
        ts.append(st);
    }
    int task;
    cin >> task;
    switch (task)
    {
    case 1:
        for (int i = 0; i < k; i++)
        {
            cout << i;
            cout << (i == k - 1 ? "\n" : ",");
        }
        for (int i = 0; i < k; i++)
        {
            int index = bs.Search(i);
            if (index == -1)
            {
                cout << "," << (i == k - 1 ? "\n" : "");
            }
            else
            {
                cout << i << (i == k - 1 ? "\n" : ",");
            }
        }
        for (int i = 0; i < k; i++)
        {
            int index = ts.Search(i);
            if (index == -1)
            {
                cout << "," << (i == k - 1 ? "\n" : "");
            }
            else
            {
                cout << i << (i == k - 1 ? "\n" : ",");
            }
        }
    }
    return 0;
}