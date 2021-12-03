#include "Stack.cpp"
#include <assert.h>

#define DEFAULT_CAPACITY 100000
#define DEFAULT_DIRECTION 1

//===================================== class definition =====================================
template <class T>
class ArrayStack : public Stack<T>
{
private:
    int isTwoStack;
    int direction;
    long long size;
    long long initialCapacity;
    long long currentCapacity;
    T *container;
    void init(int, int);
    void reallocate();

public:
    // todo: more constructor
    ArrayStack(T *container, int initialCapacity, int direction = DEFAULT_DIRECTION);
    ArrayStack(int initialCapacity = DEFAULT_CAPACITY, int direction = DEFAULT_DIRECTION);
    ~ArrayStack();
    void clear();
    void push(T);
    T pop();
    long long length();
    T top();
    void setDirection(int direction = 1);
};
//===================================== end of class definition =====================================

//===================================== class member functions definition =====================================

//=================== private member functions definition ========================
template <class T>
void ArrayStack<T>::init(int initialCapacity, int direction)
{
    this->direction = direction;
    this->size = 0;
    this->initialCapacity = initialCapacity;
    this->currentCapacity = this->initialCapacity;
    this->container = new T[this->currentCapacity];
}

template <class T>
void ArrayStack<T>::reallocate()
{
    long long tempCapacity = this->currentCapacity * 2;
    T *temp = new T[tempCapacity];
    for (int i = 0; i < this->size; i++)
    {
        if (this->direction == 1)
        {
            temp[i] = this->container[i];
        }
        else
        {
            temp[tempCapacity - i - 1] = this->container[this->currentCapacity - i - 1];
        }
    }
    this->currentCapacity = tempCapacity;
    this->container = temp;
}
//=================== end of private member functions definition ========================

//=================== public member functions definition ========================
template <class T>
ArrayStack<T>::ArrayStack(T *container, int initialCapacity, int direction)
{
    assert(direction == 1 || direction == -1);
    assert(initialCapacity > 0);
    this->isTwoStack = 1;
    this->direction = direction;
    this->size = 0;
    this->initialCapacity = initialCapacity;
    this->currentCapacity = this->initialCapacity;
    this->container = container;
}

template <class T>
ArrayStack<T>::ArrayStack(int initialCapacity, int direction)
{
    assert(initialCapacity > 0);
    assert(direction == 1 || direction == -1);
    this->isTwoStack = 0;
    this->init(initialCapacity, direction);
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
    if (this->isTwoStack == 0)
    {
        delete[] this->container;
    }
}

template <class T>
void ArrayStack<T>::clear()
{
    if (this->isTwoStack == 0)
    {
        delete[] this->container;
    }
    //  on clearing the stack is initialized with the previous initialCapacity and direction
    // here min is applied on capacity as capacity of 2 stack 1 array constructor is set to LONG_MAX
    this->init(this->initialCapacity, this->direction);
}

template <class T>
void ArrayStack<T>::push(T item)
{
    if (this->size == this->currentCapacity)
    {
        reallocate();
    }
    if (this->direction == 1)
    {
        this->container[this->size++] = item;
    }
    else
    {
        this->container[this->currentCapacity - this->size - 1] = item;
        this->size++;
    }
}

template <class T>
T ArrayStack<T>::pop()
{
    assert(this->size > 0);
    T item;
    if (this->direction == 1)
    {
        item = this->container[this->size - 1];
    }
    else
    {
        item = this->container[this->currentCapacity - this->size];
    }
    this->size--;
    return item;
}

template <class T>
long long ArrayStack<T>::length()
{
    return this->size;
}

template <class T>
T ArrayStack<T>::top()
{
    assert(this->size > 0);
    if (this->direction == 1)
    {
        return this->container[this->size - 1];
    }
    else
    {
        return this->container[this->currentCapacity - this->size];
    }
}

template <class T>
void ArrayStack<T>::setDirection(int direction)
{
    assert(this->size == 0);
    assert(direction == 1 || direction == -1);
    this->direction = direction;
}
//=================== end of public member functions definition ========================

//===================================== class member functions definition =====================================