template <class E>

/**
 * @brief     
 * Things to keep in mind:
    1| can't call getValue(), currPos(), moveToPos() for an empty list.
    2| inserting or appending to an empty list automatically make the first element the current element by increasing size.
    3| if the current position points to last element and it is removed then current position will shift back to point to the last element.
    4| otherwise after removal of current element, current position will point to next element. 
    5| current position can not point to None 
 * 
 */
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
    virtual int currPos() const = 0;
    virtual void moveToPos(int pos) = 0;
    virtual E getValue() const = 0;
    virtual int Search(E item) const = 0;
};