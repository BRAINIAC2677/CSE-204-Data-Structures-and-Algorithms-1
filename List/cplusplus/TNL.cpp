#include <iostream>
//#include "LinkedList.cpp"
#include "ArrayList.cpp"
using namespace std;

int main()
{
    int k, b, t;
    cin >> k >> b;
    //LinkedList<int> bs(b);
    ArrayList<int> bs(b);
    for (int i = 0; i < b; i++)
    {
        int st;
        cin >> st;
        bs.append(st);
    }
    cin >> t;
    //LinkedList<int> ts(t);
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
        for (int i = 0, j = 0; i < bs.length(); i++, j++)
        {
            int cur = bs.getValue();
            while (j < cur)
            {
                cout << ",";
                j++;
            }
            cout << cur;
            if (cur != k - 1)
            {
                cout << ",";
            }
            bs.next();
        }
        cout << "\n";
        for (int i = 0, j = 0; i < ts.length(); i++, j++)
        {
            int cur = ts.getValue();
            while (j < cur)
            {
                cout << ",";
                j++;
            }
            cout << cur;
            if (cur != k - 1)
            {
                cout << ",";
            }
            ts.next();
        }
    }
    return 0;
}