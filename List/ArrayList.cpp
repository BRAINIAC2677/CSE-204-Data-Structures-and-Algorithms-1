#include <cassert>
#include "List.cpp"
using namespace std;

template <class E>
class ArrayList : public List<E>
{
private:
    int listSize;
    int maxSize;
    int cur;
    E *listArray;
    void increaseSize(); //private helper function

public:
    ArrayList(int maxSize = 1000);
    ArrayList(ArrayList<E> &);
    ~ArrayList();
    void clear();
    void insert(E item);
    void append(E item);
    E remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length() const;
    int curPos() const;
    void moveToPos(int pos);
    E getValue() const;
    int Search(E item) const;

    ArrayList<E> &operator=(ArrayList<E> &);
};

template <class E>
void ArrayList<E>::increaseSize()
{
    if (listSize == maxSize)
    {
        maxSize *= 2;
        E *newArray = new E[maxSize];
        for (int i = 0; i < listSize; i++)
        {
            newArray[i] = listArray[i];
        }
        delete[] listArray;
        listArray = newArray;
    }
}

template <class E>
ArrayList<E>::ArrayList(int maxsize)
{
    listSize = 0;
    maxSize = maxsize;
    cur = 0;
    listArray = new E[maxSize];
}

template <class E>
ArrayList<E>::ArrayList(ArrayList<E> &l)
{
    listSize = l.length();
    maxSize = listSize;
    cur = l.curPos();
    listArray = new E[maxSize];
    for (int i = 0; i < listSize; i++)
    {
        listArray[i] = l.getValue();
        l.next();
    }
    l.moveToPos(cur);
}

template <class E>
ArrayList<E>::~ArrayList()
{
    delete[] listArray;
}

/**
 * @brief clearing the list with O(size) complexity
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::clear()
{
    listSize = 0;
    cur = 0;
    delete[] listArray;
    listArray = new E[maxSize];
}

/**
 * @brief inserting in the current position with O(size) complexity
 * 
 * @tparam E 
 * @param item 
 */
template <class E>
void ArrayList<E>::insert(E item)
{
    if (listSize == maxSize)
    {
        increaseSize();
        assert(listSize < maxSize);
    }
    for (int i = listSize; i > cur; i--)
        listArray[i] = listArray[i - 1];
    listArray[cur] = item;
    listSize++;
}

/**
 * @brief appending at the end of the list with O(1) complexity
 * 
 * @tparam E 
 * @param item 
 */
template <class E>
void ArrayList<E>::append(E item)
{
    if (listSize == maxSize)
    {
        increaseSize();
        assert(listSize < maxSize);
    }
    listArray[listSize] = item;
    listSize++;
}

/**
 * @brief removing the current element with O(size) complexity
 * 
 * @tparam E 
 * @return E 
 */
template <class E>
E ArrayList<E>::remove()
{
    assert(listSize > 0);
    E temp = listArray[cur];
    for (int i = cur; i < listSize - 1; i++)
        listArray[i] = listArray[i + 1];
    listSize--;
    return temp;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::moveToStart()
{
    cur = 0;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::moveToEnd()
{
    cur = listSize;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::prev()
{
    if (cur > 0)
        cur--;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::next()
{
    if (cur < listSize)
        cur++;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 * @return int 
 */
template <class E>
int ArrayList<E>::length() const
{
    return listSize;
}

/**
 * @brief returns the current position with O(1) complexity
 * 
 * @tparam E 
 * @return int 
 */
template <class E>
int ArrayList<E>::curPos() const
{
    return cur;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 * @param pos 
 */
template <class E>
void ArrayList<E>::moveToPos(int pos)
{
    assert(pos >= 0 && pos <= listSize);
    cur = pos;
}

/**
 * @brief returns the current value with O(1) complexity
 * 
 * @tparam E 
 * @return E 
 */
template <class E>
E ArrayList<E>::getValue() const
{
    assert((cur >= 0) && (cur < listSize));
    return listArray[cur];
}

/**
 * @brief returns the index of the first occurance and -1 if not present in the list. Complexity O(size).
 * 
 * @tparam E 
 * @param item 
 * @return int 
 */
template <class E>
int ArrayList<E>::Search(E item) const
{
    for (int i = 0; i < listSize; i++)
    {
        if (listArray[i] == item)
            return i;
    }
    return -1;
}

/**
 * @brief assignment operator overloading
 * 
 * @tparam E 
 * @param a 
 * @return ArrayList<E>& 
 */
template <class E>
ArrayList<E> &ArrayList<E>::operator=(ArrayList<E> &l)
{
    listSize = l.length();
    maxSize = listSize;
    cur = l.curPos();
    listArray = new E[maxSize];
    for (int i = 0; i < listSize; i++)
    {
        listArray[i] = l.getValue();
        l.next();
    }
    l.moveToPos(cur);
    return l;
}