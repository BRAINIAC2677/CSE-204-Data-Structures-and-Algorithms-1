#include <cassert>
#include "List.cpp"
using namespace std;

#define defaultSize 100000

template <class E>
class ArrayList : public List<E>
{
private:
    int size;
    int chunkSize;
    int capacity;
    int curr;
    E *listArray;
    void increaseSize(); //private helper function

public:
    ArrayList(int chunkSize = defaultSize);
    ArrayList(ArrayList<E> &);
    ArrayList(int chunkSize, ArrayList<E> &);
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
    int currPos() const;
    void moveToPos(int pos);
    E getValue() const;
    int Search(E item) const;

    ArrayList<E> &operator=(ArrayList<E> &);
};

template <class E>
void ArrayList<E>::increaseSize()
{
    if (this->size == this->capacity)
    {
        this->capacity += this->chunkSize;
        E *newArray = new E[this->capacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = listArray[i];
        }
        delete[] listArray;
        listArray = newArray;
    }
}

template <class E>
ArrayList<E>::ArrayList(int chunkSize)
{
    assert(chunkSize > 0);
    this->chunkSize = chunkSize;
    this->capacity = chunkSize;
    this->size = 0;
    curr = 0;
    listArray = new E[this->capacity];
}

template <class E>
ArrayList<E>::ArrayList(ArrayList<E> &list)
{
    this->size = list.length();
    this->chunkSize = this->capacity = this->size;
    this->curr = list.currPos();
    this->listArray = new E[this->capacity];
    for (int i = 0; i < size; i++)
    {
        listArray[i] = list.getValue();
        list.next();
    }
    list.moveToPos(curr);
}

template <class E>
ArrayList<E>::ArrayList(int chunkSize, ArrayList<E> &list)
{
    assert(chunkSize > 0);
    assert(chunkSize >= list.length());
    this->chunkSize = this->capacity = chunkSize;
    this->size = list.length();
    this->curr = list.currPos();
    this->listArray = new E[this->capacity];
    for (int i = 0; i < size; i++)
    {
        listArray[i] = list.getValue();
        list.next();
    }
    list.moveToPos(curr);
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
    this->size = 0;
    this->curr = 0;
    this->capacity = this->chunkSize;
    delete[] listArray;
    this->listArray = new E[this->capacity];
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
    if (size == capacity)
    {
        increaseSize();
    }
    for (int i = size; i > curr; i--)
        listArray[i] = listArray[i - 1];
    listArray[curr] = item;
    size++;
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
    if (size == capacity)
    {
        increaseSize();
    }
    listArray[size] = item;
    size++;
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
    assert(size > 0);
    E temp = listArray[curr];
    for (int i = curr; i < size - 1; i++)
        listArray[i] = listArray[i + 1];
    size--;
    if (this->curr >= this->size)
    {
        this->curr = max(0, this->size - 1);
    }
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
    curr = 0;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::moveToEnd()
{
    this->curr = max(0, this->size - 1);
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::prev()
{
    if (curr > 0)
        curr--;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void ArrayList<E>::next()
{
    this->curr = min(this->size - 1, this->curr + 1);
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
    return size;
}

/**
 * @brief returns the current position with O(1) complexity
 * 
 * @tparam E 
 * @return int 
 */
template <class E>
int ArrayList<E>::currPos() const
{
    assert(this->size > 0);
    return curr;
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
    assert(pos >= 0 && pos < size);
    curr = pos;
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
    assert(this->size > 0);
    return listArray[curr];
}

/**
 * @brief returns the index of the first occurrance and -1 if not present in the list. Complexity O(size).
 * 
 * @tparam E 
 * @param item 
 * @return int 
 */
template <class E>
int ArrayList<E>::Search(E item) const
{
    for (int i = 0; i < size; i++)
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
    size = l.length();
    chunkSize = capacity = size;
    curr = l.currPos();
    listArray = new E[capacity];
    for (int i = 0; i < size; i++)
    {
        listArray[i] = l.getValue();
        l.next();
    }
    l.moveToPos(curr);
    return l;
}