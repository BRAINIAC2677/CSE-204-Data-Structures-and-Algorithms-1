/*
Author: Asif Azad
Date: 27/01/2022


Algorithm: Merge Sort for int, long long int, float, double, char, string

possible parameter combination:
1| msort(vector_name)
2| msort(vector_name, comparator_function)
3| msort(vector_name, start_index, end_index)
4| msort(vector_name, start_index, end_index, comparator_function)

*/

#ifndef MSORT
#define MSORT

#include <bits/stdc++.h>
using namespace std;

template <class T>
bool defaultMcomp(T a, T b)
{
    return a < b;
}

template <class T>
void merge(vector<T> &container, int l, int m, int r, bool (*comp)(T, T))
{
    vector<T> la, ra;
    for (int i = l; i <= m; i++)
    {
        la.push_back(container[i]);
    }
    for (int i = m + 1; i <= r; i++)
    {
        ra.push_back(container[i]);
    }
    for (int i = l, lp = 0, rp = 0; i <= r; i++)
    {
        if (lp >= (size_t)la.size())
        {
            container[i] = ra[rp++];
        }
        else if (rp >= (size_t)ra.size())
        {
            container[i] = la[lp++];
        }
        else if (comp(la[lp], ra[rp]))
        {
            container[i] = la[lp++];
        }
        else
        {
            container[i] = ra[rp++];
        }
    }
}

template <class T>
void recMsort(vector<T> &container, int l, int r, bool (*comp)(T, T))
{
    if (l < r)
    {
        int m = (l + r) / 2;
        recMsort(container, l, m, comp);
        recMsort(container, m + 1, r, comp);
        merge(container, l, m, r, comp);
    }
}

template <class T>
void msort(vector<T> &container)
{
    recMsort(container, 0, container.size() - 1, defaultMcomp<T>);
}

template <class T>
void msort(vector<T> &container, bool (*comp)(T, T))
{
    recMsort(container, 0, container.size() - 1, comp);
}

template <class T>
void msort(vector<T> &container, int start, int end, bool (*comp)(T, T) = defaultMcomp<T>)
{
    assert(start >= 0 && end < container.size() && start <= end);
    recMsort(container, start, end, comp);
}

#endif