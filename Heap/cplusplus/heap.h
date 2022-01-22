/*
Author: Asif Azad
Date: 08.01.2022

Max heap for integer key values.
- one indexed arraycontainer.
*/

#include <vector>
using namespace std;

#define DEFAULT_MAX_SIZE 100000

class Heap
{
private:
    int *arrayContainer;
    int heapSize;
    int maxSize;
    void reallocate();
    void percolate(int index, bool up = true);

public:
    Heap();
    Heap(int);
    Heap(vector<int> inp);
    ~Heap();
    int size();
    void insert(int);
    int getMax();
    int deleteKey();
};

//======================== private helper functions ===========================
void Heap::reallocate()
{
    int tempMaxSize = this->maxSize * 2;
    int *tempArrayContainer = new int[tempMaxSize];
    for (int i = 1; i <= this->heapSize; i++)
    {
        tempArrayContainer[i] = this->arrayContainer[i];
    }
    delete[] this->arrayContainer;
    this->maxSize = tempMaxSize;
    this->arrayContainer = tempArrayContainer;
}

void Heap::percolate(int index, bool up)
{
    if (up)
    {
        if (index == 1)
        {
            return;
        }
        if (this->arrayContainer[index] > this->arrayContainer[index / 2])
        {
            int temp = this->arrayContainer[index];
            this->arrayContainer[index] = this->arrayContainer[index / 2];
            this->arrayContainer[index / 2] = temp;
            this->percolate(index / 2, up);
        }
    }
    else
    {
        if (index > this->heapSize / 2)
        {
            return;
        }
        int largestInd = index;
        if (2 * index <= this->heapSize && this->arrayContainer[2 * index] > this->arrayContainer[largestInd])
        {
            largestInd = 2 * index;
        }
        if (2 * index + 1 <= this->heapSize && this->arrayContainer[2 * index + 1] > this->arrayContainer[largestInd])
        {
            largestInd = 2 * index + 1;
        }
        if (largestInd != index)
        {
            int temp = this->arrayContainer[index];
            this->arrayContainer[index] = this->arrayContainer[largestInd];
            this->arrayContainer[largestInd] = temp;
            this->percolate(largestInd, up);
        }
    }
}
//======================== end of private helper functions ====================

//======================= member functions ====================================
Heap::Heap()
{
    this->heapSize = 0;
    this->maxSize = DEFAULT_MAX_SIZE;
    this->arrayContainer = new int[this->maxSize];
}

Heap::Heap(int size)
{
    this->heapSize = 0;
    this->maxSize = size;
    this->arrayContainer = new int[this->maxSize];
}

Heap::Heap(vector<int> inp)
{
    this->heapSize = 0;
    this->maxSize = inp.size() + 1;
    this->arrayContainer = new int[this->maxSize];
    for (int element : inp)
    {
        this->insert(element);
    }
}

Heap::~Heap()
{
    delete[] this->arrayContainer;
}

int Heap::size()
{
    return this->heapSize;
}

void Heap::insert(int element)
{
    if (this->heapSize >= this->maxSize - 1)
    {
        this->reallocate();
    }
    this->heapSize++;
    this->arrayContainer[this->heapSize] = element;
    this->percolate(this->heapSize);
}

int Heap::getMax()
{
    if (this->heapSize >= 1)
    {
        return this->arrayContainer[1];
    }
    return -1;
}

int Heap::deleteKey()
{
    if (this->heapSize >= 1)
    {
        int ret = this->arrayContainer[1];
        this->arrayContainer[1] = this->arrayContainer[this->heapSize];
        this->heapSize--;
        this->percolate(1, false);
        return ret;
    }
    return -1;
}

void heapsort(vector<int> &v)
{
    Heap h(v);
    int n = v.size();
    for (int i = 0; i < n-1; i++)
    {
        v[i] = h.deleteKey();
    }
}