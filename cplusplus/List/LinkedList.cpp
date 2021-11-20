#include "List.cpp"
#include <cassert>

template <class E>
class Node
{
    E element;
    Node<E> *next;

public:
    Node(E e = NULL, Node<E> *n = nullptr)
    {
        element = e;
        next = n;
    }
    E getElement() const
    {
        return element;
    }
    Node<E> *getNext() const
    {
        return next;
    }
    void setNext(Node<E> *n)
    {
        next = n;
    }
};

template <class E>
class LinkedList : public List<E>
{
    Node<E> *head;
    Node<E> *tail;
    Node<E> *cur;
    int size;

    //helper methods inaccesible to user.
    void init();
    void removeAll();

public:
    LinkedList(int maxSize = 1000);
    LinkedList(LinkedList<E> &);
    ~LinkedList();
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

    LinkedList<E> &operator=(LinkedList<E> &);
};

template <class E>
void LinkedList<E>::init()
{
    head = tail = cur = new Node<E>;
    size = 0;
}

template <class E>
void LinkedList<E>::removeAll()
{
    while (head->getNext() != nullptr)
    {
        cur = head;
        head = head->getNext();
        delete cur;
    }
}

template <class E>
LinkedList<E>::LinkedList(int maxSize)
{
    init();
}

template <class E>
LinkedList<E>::LinkedList(LinkedList<E> &l)
{
    init();
    int prevPos = l.curPos();
    for (int i = 0; i < l.length(); i++)
    {
        this->append(l.getValue());
        l.next();
    }
    l.moveToPos(prevPos);
    this->moveToPos(prevPos);
}

template <class E>
LinkedList<E>::~LinkedList()
{
    removeAll();
}

/**
 * @brief clearing the list with O(size) complexity
 * @tparam E 
 */
template <class E>
void LinkedList<E>::clear()
{
    removeAll();
    init();
}

/**
 * @brief inserting at current position with O(1) complexity
 * 
 * @tparam E 
 * @param item 
 */
template <class E>
void LinkedList<E>::insert(E item)
{
    Node<E> *newNode = new Node<E>(item);
    newNode->setNext(cur->getNext());
    cur->setNext(newNode);
    this->size++;
    //if inserted in the tail
    if (newNode->getNext() == nullptr)
    {
        tail = newNode;
    }
}

/**
 * @brief appending item to the last with O(1) complexity
 * 
 * @tparam E 
 * @param item 
 */
template <class E>
void LinkedList<E>::append(E item)
{
    Node<E> *newNode = new Node<E>(item);
    tail->setNext(newNode);
    tail = newNode;
    this->size++;
}

/**
 * @brief removing current item with O(1) complexity
 * 
 * @tparam E 
 * @return E 
 */
template <class E>
E LinkedList<E>::remove()
{
    assert(cur->getNext() != nullptr);
    this->size--;
    Node<E> *temp = cur->getNext();
    E value = temp->getElement();
    cur->setNext(temp->getNext());
    if (temp == tail)
    {
        tail = cur;
    }
    delete temp;
    return value;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::moveToStart()
{
    cur = head;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::moveToEnd()
{
    cur = tail;
}

/**
 * @brief complexity O(size)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::prev()
{
    if (cur == head)
    {
        return;
    }
    Node<E> *temp = head;
    while (temp->getNext() != cur)
    {
        temp = temp->getNext();
    }
    cur = temp;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::next()
{
    if (cur == tail)
    {
        return;
    }
    cur = cur->getNext();
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 * @return int 
 */
template <class E>
int LinkedList<E>::length() const
{
    return this->size;
}

/**
 * @brief returns the current position with O(size) complexity
 * 
 * @tparam E 
 * @return int 
 */
template <class E>
int LinkedList<E>::curPos() const
{
    int index = 0;
    Node<E> *temp = head;
    while (temp != cur)
    {
        index++;
        temp = temp->getNext();
    }
    return index;
}

/**
 * @brief complexity O(size)
 * 
 * @tparam E 
 * @param pos 
 */
template <class E>
void LinkedList<E>::moveToPos(int pos)
{
    assert((pos >= 0) && (pos <= this->size));
    cur = head;
    for (int i = 0; i < pos; i++)
    {
        cur = cur->getNext();
    }
}

/**
 * @brief returns the current value with O(1) complexity
 * 
 * @tparam E 
 * @return E 
 */
template <class E>
E LinkedList<E>::getValue() const
{
    assert(cur->getNext() != nullptr);
    return cur->getNext()->getElement();
}

/**
 * @brief returns the index of the first occurance or -1 if not present with O(size) complexity.
 * 
 * @tparam E 
 * @param item 
 * @return int 
 */
template <class E>
int LinkedList<E>::Search(E item) const
{
    int index = 0;
    for (Node<E> *temp = head; index < this->size; index++)
    {
        if (temp->getElement() == item)
        {
            return index;
        }
        temp = temp->getNext();
    }
    return -1;
}

/**
 * @brief complexity O(size)
 * 
 * @tparam E 
 * @param l 
 * @return LinkedList<E>& 
 */

/**
 * @brief have bugs
 * 
 * @tparam E 
 * @param l 
 * @return LinkedList<E>& 
 */
template <class E>
LinkedList<E> &LinkedList<E>::operator=(LinkedList<E> &l)
{
    init();
    int prevPos = l.curPos();
    for (int i = 0; i < l.length(); i++)
    {
        this->append(l.getValue());
        l.next();
    }
    l.moveToPos(prevPos);
    this->moveToPos(prevPos);
    return l;
}