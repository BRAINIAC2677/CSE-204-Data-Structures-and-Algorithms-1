#include <bits/stdc++.h>
#include "msort.h"
#include "qsort.h"
#include "isort.h"
using namespace std;

enum algorithms
{
    MERGE_SORT,
    QUICK_SORT,
    RANDOMIZED_QUICK_SORT,
    INSERTION_SORT,
    STL,
    LAST
};

vector<int> randomArray(int n, int seed)
{
    srand(seed);
    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        ret.push_back(rand());
    }
    return ret;
}

float sortingTime(vector<int> ra, algorithms algo)
{
    clock_t start = clock();
    switch (algo)
    {
    case algorithms::MERGE_SORT:
        msort(ra);
        break;
    case algorithms::QUICK_SORT:
        qsort(ra);
        break;
    case algorithms::RANDOMIZED_QUICK_SORT:
        rqsort(ra);
        break;
    case algorithms::INSERTION_SORT:
        isort(ra);
        break;
    case algorithms::STL:
        sort(ra.begin(), ra.end());
        break;
    default:
        break;
    }
    clock_t end = clock();
    return float(end - start) / CLOCKS_PER_SEC * 1000; //time in ms
}

/*
1| iteration no is used as seed
2| returned vector format: n,msort,qsort,rqsort,isort,stl,qsort on sorted,rqsort on sorted
*/
vector<float> avgSortingTimes(int n, int iterations = 20)
{
    vector<float> times(8);
    for (int i = 0; i < iterations; i++)
    {
        for (int j = algorithms::MERGE_SORT; j != algorithms::LAST; j++)
        {
            times[j + 1] += sortingTime(randomArray(n, iterations), algorithms(j));
        }
        vector<int> sortedArray = randomArray(n, iterations);
        msort(sortedArray);
        times[6] += sortingTime(sortedArray, algorithms::QUICK_SORT);
        times[7] += sortingTime(sortedArray, algorithms::RANDOMIZED_QUICK_SORT);
    }
    for (auto &times : times)
    {
        times /= iterations;
    }
    times[0] = n;
    return times;
}

template <class T>
void print_csv(ostream &out, vector<T> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        out << values[i] << (i == values.size() - 1 ? '\n' : ',');
    }
}

int main()
{
    string header = "n,MergeSort(ms),QuickSort(ms),Randomized QuickSort(ms),InsertionSort(ms),STL(ms),QuickSort With Sorted Input(ms),Randomized QuickSort With Sorted Input(ms)\n";

    ofstream out("output.csv", ios::out);
    vector<int> n_values = {5, 10, 100, 1000, 10000};
    out << header;
    for (auto n : n_values)
    {
        print_csv(out, avgSortingTimes(n, 5));
    }
    out.close();

    return 0;
}