
template <class K, class D>
class BinNode
{
private:
    K key;
    D data;
    BinNode<K, D> *lc, *rc;

public:
    BinNode(K key, D data = NULL, BinNode<K, D> *lc = nullptr, BinNode<K, D> *rc = nullptr)
    {
        this->key = key;
        this->data = data;
        this->lc = lc;
        this->rc = rc;
    }
    ~BinNode() {}

    K getKey()
    {
        return this->key;
    }
    void setKey(K key)
    {
        this->key = key;
    }
    D getData()
    {
        return this->data;
    }
    void setData(D data)
    {
        this->data = data;
    }
    BinNode<K, D> *getLeftChild() const
    {
        return this->lc;
    }
    void setLeftChild(BinNode<K, D> *lc)
    {
        this->lc = lc;
    }
    BinNode<K, D> *getRightChild() const
    {
        return this->rc;
    }
    void setRightChild(BinNode<K, D> *rc)
    {
        this->rc = rc;
    }
    int isLeaf()
    {
        return ((this->lc == nullptr) && (this->rc == nullptr));
    }
};