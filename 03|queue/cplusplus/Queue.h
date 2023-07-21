#ifndef QUEUE
#define QUEUE

template <class T>
class Queue
{
private:
    Queue(const Queue &) {}
    void operator=(const Queue &) {}

public:
    Queue() {}
    virtual void clear() = 0;
    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual int length() const = 0;
    virtual T frontValue() const = 0;
    virtual T rearValue() const = 0;
    virtual T leaveQueue() = 0;
};

#endif