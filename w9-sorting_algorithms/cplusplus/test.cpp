#include <bits/stdc++.h>
#include "msort.h"
#include "qsort.h"
#include "isort.h"
using namespace std;

template <class T>
bool comp(T a, T b)
{
    return a > b;
}

int main()
{
    vector<int> a = {5, 4, -1, 0, 5};
    vector<long long int> b = {10000000, 400000000000, 1, -1, -3000000};
    vector<float> c = {1.1, 1.12, 1.07, 2.21, -0.1};
    vector<double> d = {2677.0, 2.677, 0.2677, 26.77, 267.7};
    vector<char> e = {'a', 'x', 'b', 'c', 'b'};
    vector<string> f = {"aa", "ab", "xy", "xd", "aaa"};

    rqsort(a);
    rqsort(b, comp);
    rqsort(c, 0, 2);
    rqsort(d, 0, 2, comp);
    rqsort(e);
    rqsort(f);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << (i == a.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << (i == b.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << (i == c.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << (i == d.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < e.size(); i++)
    {
        cout << e[i] << (i == e.size() - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << (i == f.size() - 1 ? '\n' : ' ');
    }
    return 0;
}