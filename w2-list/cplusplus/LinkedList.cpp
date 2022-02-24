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
    Node<E> *curr;
    int size;

    //helper methods inaccesible to user.
    void init();
    void removeAll();

public:
    LinkedList();
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
    int currPos() const;
    void moveToPos(int pos);
    E getValue() const;
    int Search(E item) const;

    LinkedList<E> &operator=(LinkedList<E> &);
};

template <class E>
void LinkedList<E>::init()
{
    head = tail = curr = new Node<E>;
    size = 0;
}

template <class E>
void LinkedList<E>::removeAll()
{
    while (head->getNext() != nullptr)
    {
        curr = head;
        head = head->getNext();
        delete curr;
    }
}

template <class E>
LinkedList<E>::LinkedList()
{
    init();
}

template <class E>
LinkedList<E>::LinkedList(LinkedList<E> &l)
{
    init();
    if (l.length() > 0)
    {
        int prevPos = l.currPos();
        for (int i = 0; i < l.length(); i++)
        {
            this->append(l.getValue());
            l.next();
        }
        l.moveToPos(prevPos);
        this->moveToPos(prevPos);
    }
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
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
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
    assert(this->size > 0);
    this->size--;
    Node<E> *temp = curr->getNext();
    E value = temp->getElement();
    curr->setNext(temp->getNext());
    if (temp == tail)
    {
        tail = curr;
        this->prev();
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
    curr = head;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::moveToEnd()
{
    while (this->curr->getNext() != this->tail)
    {
        this->next();
    }
}

/**
 * @brief complexity O(size)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::prev()
{
    if (curr == head)
    {
        return;
    }
    Node<E> *temp = head;
    while (temp->getNext() != curr)
    {
        temp = temp->getNext();
    }
    curr = temp;
}

/**
 * @brief complexity O(1)
 * 
 * @tparam E 
 */
template <class E>
void LinkedList<E>::next()
{
    if (curr == tail || curr->getNext() == tail)
    {
        return;
    }
    curr = curr->getNext();
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
int LinkedList<E>::currPos() const
{
    assert(this->size > 0);
    int index = 0;
    Node<E> *temp = head;
    while (temp != curr)
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
    curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
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
    assert(this->size > 0);
    return curr->getNext()->getElement();
}

/**
 * @brief returns the index of the first occurrance or -1 if not present with O(size) complexity.
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
        if (temp->getNext()->getElement() == item)
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
 * @brief 
 * 
 * @tparam E 
 * @param l 
 * @return LinkedList<E>& 
 */
template <class E>
LinkedList<E> &LinkedList<E>::operator=(LinkedList<E> &l)
{
    init();
    int prevPos = l.currPos();
    for (int i = 0; i < l.length(); i++)
    {
        this->append(l.getValue());
        l.next();
    }
    l.moveToPos(prevPos);
    this->moveToPos(prevPos);
    return l;
}