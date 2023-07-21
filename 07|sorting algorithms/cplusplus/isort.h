/*
Author: Asif Azad
Date: 27/01/2022


Algorithm: Insertion Sort for int, long long int, float, double, char, string

possible parameter combination:
1| isort(vector_name)
2| isort(vector_name, comparator_function)
3| isort(vector_name, start_index, end_index)
4| isort(vector_name, start_index, end_index, comparator_function)

*/

#ifndef ISORT
#define ISORT

#include <bits/stdc++.h>
using namespace std;

template <class T>
bool defaultIcomp(T a, T b)
{
    return a < b;
}

template <class T>
void isortHelper(vector<T> &container, int start, int end, bool (*comp)(T, T))
{
    for (int i = start + 1; i <= end; i++)
    {
        T key = container[i];
        int j = i - 1;
        while (j >= start && comp(key, container[j]))
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

template <class T>
void isort(vector<T> &container)
{
    isortHelper(container, 0, container.size() - 1, defaultIcomp<T>);
}

template <class T>
void isort(vector<T> &container, bool (*comp)(T, T))
{
    isortHelper(container, 0, container.size() - 1, comp);
}

template <class T>
void isort(vector<T> &container, int start, int end, bool (*comp)(T, T) = defaultIcomp<T>)
{
    assert(start >= 0 && end < container.size() && start <= end);
    isortHelper(container, start, end, comp);
}

#endif