#include "Queue.h"
#include <assert.h>
#define DEFAULT_CAPACITY 1000

template <class T>
class ArrayQueue : public Queue<T>
{
private:
    int isContainerGiven;
    int maxCapacity;
    int front;
    int rear;
    T *container;
    void init(int maxCapacity);
    void reallocate();

public:
    ArrayQueue(int maxCapacity = DEFAULT_CAPACITY);
    ArrayQueue(T *, int);
    ~ArrayQueue();
    void clear();
    void enqueue(T item);
    T dequeue();
    int length() const;
    T frontValue() const;
    T rearValue() const;
    T leaveQueue();
};

template <class T>
void ArrayQueue<T>::init(int maxCapacity)
{
    this->maxCapacity = maxCapacity;
    this->container = new T[maxCapacity];
    this->rear = 0;
    this->front = 1;
}

template <class T>
void ArrayQueue<T>::reallocate()
{
    T *tempContainer = new T[this->maxCapacity * 2];
    for (int i = front;; i = (i + 1) % this->maxCapacity)
    {
        tempContainer[i] = this->container[i];
        if (i == rear)
        {
            break;
        }
    }
    this->container = tempContainer;
    this->maxCapacity *= 2;
}

template <class T>
ArrayQueue<T>::ArrayQueue(int maxCapacity)
{
    this->isContainerGiven = 0;
    this->init(maxCapacity);
}

template <class T>
ArrayQueue<T>::ArrayQueue(T *container, int size)
{
    this->isContainerGiven = 1;
    this->maxCapacity = size;
    this->rear = 0;
    this->front = 1;
}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{
    if (this->isContainerGiven == 0)
    {
        delete[] this->container;
    }
}

template <class T>
void ArrayQueue<T>::clear()
{
    this->rear = 0;
    this->front = 1;
}

template <class T>
void ArrayQueue<T>::enqueue(T item)
{
    if ((this->rear + 2) % this->maxCapacity == this->front)
    {
        this->reallocate();
    }
    this->rear = (this->rear + 1) % this->maxCapacity;
    this->container[this->rear] = item;
}

template <class T>
T ArrayQueue<T>::dequeue()
{
    assert(this->length() > 0);
    T ret = this->container[this->front];
    this->front = (this->front + 1) % this->maxCapacity;
    return ret;
}

template <class T>
int ArrayQueue<T>::length() const
{
    return (this->rear - this->front + 1 + this->maxCapacity) % this->maxCapacity;
}

template <class T>
T ArrayQueue<T>::frontValue() const
{
    assert(this->length() > 0);
    return this->container[this->front];
}

template <class T>
T ArrayQueue<T>::rearValue() const
{
    assert(this->length() > 0);
    return this->container[this->rear];
}

template <class T>
T ArrayQueue<T>::leaveQueue()
{
    assert(this->length() > 0);
    T ret = this->container[this->rear];
    this->rear = (this->rear - 1 + this->maxCapacity) % this->maxCapacity;
    return ret;
}