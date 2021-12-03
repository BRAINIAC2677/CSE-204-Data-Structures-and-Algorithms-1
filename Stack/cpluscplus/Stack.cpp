#ifndef STACK
#define STACK

template <class T>
class Stack
{
private:
    void operator=(const Stack &) {}
    Stack(const Stack &) {}

public:
    Stack() {}
    virtual ~Stack() {}
    virtual void clear() = 0;
    virtual void push(T) = 0;
    virtual T pop() = 0;
    virtual long long length() = 0;
    virtual T top() = 0;
    virtual void setDirection(int) {} // only Array base implementation will override setDirection as this is not relevant for LinkList based implementatin.
};

#endif
