template <class E>
class List
{
public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;
    virtual void insert(E item) = 0;
    virtual void append(E item) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() const = 0;
    virtual int curPos() const = 0;
    virtual void moveToPos(int pos) = 0;
    virtual E getValue() const = 0;
    virtual int Search(E item) const = 0;
};