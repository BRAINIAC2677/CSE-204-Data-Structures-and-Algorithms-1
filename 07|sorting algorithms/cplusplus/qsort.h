/*
Author: Asif Azad
Date: 27/01/2022


Algorithm: Quick Sort(qsort) and Randomized Quick Sort(rqsort) for int, long long int, float, double, char, string

possible parameter combinations:
1| qsort(vector_name)
2| qsort(vector_name, comparator_function)
3| qsort(vector_name, start_index, end_index)
4| qsort(vector_name, start_index, end_index, comparator_function)

5| rqsort(vector_name)
6| rqsort(vector_name, comparator_function)
7| rqsort(vector_name, start_index, end_index) 
8| rqsort(vector_name, start_index, end_index, comparator_function)
*/

#ifndef QSORT
#define QSORT

#include <bits/stdc++.h>
using namespace std;

template <class T>
bool defaultQcomp(T a, T b)
{
    return a < b;
}

template <class T>
int partition(vector<T> &container, int l, int r, bool (*comp)(T, T), bool isRandomized)
{

    int pivotInd = r;
    if (isRandomized)
    {
        srand(time(nullptr));
        pivotInd = l + rand() % (r - l + 1);
    }
    T pivot = container[pivotInd];
    int i = l - 1, j = l;
    for (; j < r; j++)
    {
        if (comp(container[j], pivot))
        {
            i++;
            swap(container[i], container[j]);
        }
    }
    swap(container[i + 1], container[pivotInd]);
    return i + 1;
}

template <class T>
void recQsort(vector<T> &container, int l, int r, bool (*comp)(T, T), bool isRandomized = false)
{
    if (l < r)
    {
        int p = partition(container, l, r, comp, isRandomized);
        recQsort(container, l, p - 1, comp, isRandomized);
        recQsort(container, p + 1, r, comp, isRandomized);
    }
}

//============================= quick sort ==========================
template <class T>
void qsort(vector<T> &container)
{
    recQsort(container, 0, container.size() - 1, defaultQcomp<T>, false);
}

template <class T>
void qsort(vector<T> &container, bool (*comp)(T, T))
{
    recQsort(container, 0, container.size() - 1, comp, false);
}

template <class T>
void qsort(vector<T> &container, int start, int end, bool (*comp)(T, T) = defaultQcomp<T>)
{
    assert(start >= 0 && end < container.size() && start <= end);
    recQsort(container, start, end, comp, false);
}

//============================== randomized quick sort ======================
template <class T = int>
void rqsort(vector<T> &container)
{
    recQsort(container, 0, container.size() - 1, defaultQcomp<T>, true);
}

template <class T>
void rqsort(vector<T> &container, bool (*comp)(T, T))
{
    recQsort(container, 0, container.size() - 1, comp, true);
}

template <class T>
void rqsort(vector<T> &container, int start, int end, bool (*comp)(T, T) = defaultQcomp<T>)
{
    assert(start >= 0 && end < container.size() && start <= end);
    recQsort(container, start, end, comp, true);
}

#endif