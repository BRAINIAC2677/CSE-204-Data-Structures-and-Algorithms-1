#include <assert.h>
#include "Stack.cpp"

template <class T>
class Node
{
    T element;
    Node<T> *next;

public:
    Node(T e = NULL, Node<T> *n = nullptr)
    {
        element = e;
        next = n;
    }
    T getElement() const
    {
        return element;
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
class LinkedStack : public Stack<T>
{
private:
    long long size;
    Node<T> *topNode;
    void init();
    void deallocate();

public:
    LinkedStack();
    ~LinkedStack();
    void clear();
    void push(T);
    T pop();
    long long length();
    T top();
};

template <class T>
void LinkedStack<T>::init()
{
    this->size = 0;
    this->topNode = nullptr;
}

template <class T>
void LinkedStack<T>::deallocate()
{
    while (this->size > 0)
    {
        this->pop();
    }
}

template <class T>
LinkedStack<T>::LinkedStack()
{
    this->init();
}

template <class T>
LinkedStack<T>::~LinkedStack()
{
    this->deallocate();
}

template <class T>
void LinkedStack<T>::clear()
{
    this->deallocate();
    this->init();
}

template <class T>
void LinkedStack<T>::push(T item)
{
    this->size++;
    Node<T> *temp = this->topNode;
    this->topNode = new Node<T>(item);
    this->topNode->setNext(temp);
}

template <class T>
T LinkedStack<T>::pop()
{
    assert(this->size > 0);
    this->size--;
    T item = this->topNode->getElement();
    Node<T> *temp = this->topNode->getNext();
    delete this->topNode;
    this->topNode = temp;
    return item;
}

template <class T>
long long LinkedStack<T>::length()
{
    return this->size;
}

template <class T>
T LinkedStack<T>::top()
{
    assert(this->size > 0);
    return this->topNode->getElement();
}
