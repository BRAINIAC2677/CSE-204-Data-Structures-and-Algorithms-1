#include "Queue.h"
#include <assert.h>
#include <stdio.h>
using namespace std;

/*
Unfixed bug in LinkedQueue. Gets random segmentation fault on operations.
*/
template <class T>
class Node
{
    T element;
    Node<T> *next;

public:
    Node(T e = {}, Node<T> *n = nullptr)
    {
        element = e;
        next = n;
    }
    T getElement() const
    {
        return element;
    }
    void setElement(const T &element)
    {
        this->element = element;
    }
    Node<T> *getNext() const
    {
        return next;
    }
    void setNext(Node<T> *n)
    {
        next = n;
    }
};

template <class T>
class LinkedQueue : public Queue<T>
{
private:
    Node<T> *front, *rear;
    int size;

public:
    LinkedQueue();
    ~LinkedQueue();
    void clear();
    void enqueue(T item);
    T dequeue();
    int length() const;
    T frontValue() const;
    T rearValue() const;
    T leaveQueue();
};

template <class T>
LinkedQueue<T>::LinkedQueue()
{
    this->front = this->rear = new Node<T>;
    this->size = 0;
}

template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    this->clear();
    delete this->front;
}

template <class T>
void LinkedQueue<T>::clear()
{
    while (this->size > 0)
    {
        this->dequeue();
    }
}

template <class T>
void LinkedQueue<T>::enqueue(T item)
{
    assert(this->rear);
    Node<T> *newNode = new Node<T>(item);
    this->rear->setNext(newNode);
    this->rear = this->rear->getNext();
    this->size++;
}

template <class T>
T LinkedQueue<T>::dequeue()
{
    assert(this->size > 0);
    this->size--;
    Node<T> *temp = this->front->getNext();
    T ret = temp->getElement();
    this->front->setNext(temp->getNext());
    if (temp == this->rear)
    {
        this->rear = this->front;
    }
    delete temp;
    return ret;
}

template <class T>
int LinkedQueue<T>::length() const
{
    return this->size;
}

template <class T>
T LinkedQueue<T>::frontValue() const
{
    assert(this->size > 0);
    return (this->front->getNext())->getElement();
}

template <class T>
T LinkedQueue<T>::rearValue() const
{
    assert(this->size > 0);
    return this->rear->getElement();
}

template <class T>
T LinkedQueue<T>::leaveQueue()
{
    assert(this->size > 0);
    this->size--;
    Node<T> *temp = this->front;
    while (temp->getNext() != this->rear)
    {
        temp = temp->getNext();
    }
    T ret = this->rear->getElement();
    delete this->rear;
    this->rear = temp;
    return ret;
}