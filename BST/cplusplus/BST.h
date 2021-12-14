#include "BinNode.h"
#include <ostream>
using namespace std;

template <class K, class D>
class BST
{
private:
    BinNode<K, D> *root;
    int nodeCount;

    BinNode<K, D> *deleteMin(BinNode<K, D> *root);
    BinNode<K, D> *getMin(BinNode<K, D> *root);
    D findHelp(BinNode<K, D> *root, K key);
    BinNode<K, D> *insertHelp(BinNode<K, D> *root, K key, D data);
    BinNode<K, D> *removeHelp(BinNode<K, D> *root, K key);
    void clearHelp(BinNode<K, D> *root);
    void printHelp(BinNode<K, D> *root, ostream &out);
    void preorderHelp(BinNode<K, D> *root, ostream &out);
    void inorderHelp(BinNode<K, D> *root, ostream &out);
    void postorderHelp(BinNode<K, D> *root, ostream &out);

public:
    BST();
    ~BST();
    void clear();
    D find(K key);
    void insert(K key, D data);
    int remove(K key); // return 0 if the key is not found otherwise 1
    int length();
    void print(ostream &out);
    void preorder(ostream &out);
    void inorder(ostream &out);
    void postorder(ostream &out);
};

//=============================================private helper functions============================================
template <class K, class D>
BinNode<K, D> *BST<K, D>::deleteMin(BinNode<K, D> *root)
{
    if (root->getLeftChild() == nullptr)
    {
        return root->getRightChild();
    }
    root->setLeftChild(deleteMin(root->getLeftChild()));
    return root;
}

template <class K, class D>
BinNode<K, D> *BST<K, D>::getMin(BinNode<K, D> *root)
{
    if (root->getLeftChild() == nullptr)
    {
        return root;
    }
    return getMin(root->getLeftChild());
}

template <class K, class D>
D BST<K, D>::findHelp(BinNode<K, D> *root, K key)
{
    if (root == nullptr)
    {
        return NULL;
    }
    else if (key < root->getKey())
    {
        return findHelp(root->getLeftChild(), key);
    }
    else if (key > root->getKey())
    {
        return findHelp(root->getRightChild(), key);
    }
    else
    {
        return root->getData();
    }
}

template <class K, class D>
BinNode<K, D> *BST<K, D>::insertHelp(BinNode<K, D> *root, K key, D data)
{
    if (root == nullptr)
    {
        return new BinNode<K, D>(key, data);
    }
    if (key < root->getKey())
    {
        root->setLeftChild(insertHelp(root->getLeftChild(), key, data));
    }
    else
    {
        root->setRightChild(insertHelp(root->getRightChild(), key, data));
    }
    return root;
}

template <class K, class D>
BinNode<K, D> *BST<K, D>::removeHelp(BinNode<K, D> *root, K key)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (key < root->getKey())
    {
        root->setLeftChild(removeHelp(root->getLeftChild(), key));
    }
    else if (key > root->getKey())
    {
        root->setRightChild(removeHelp(root->getRightChild(), key));
    }
    else
    {
        BinNode<K, D> *temp = root;
        if (root->getLeftChild() == nullptr)
        {
            root = root->getRightChild();
        }
        else if (root->getRightChild() == nullptr)
        {
            root = root->getLeftChild();
        }
        else
        {
            temp = this->getMin(root->getRightChild());
            root->setKey(temp->getKey());
            root->setData(temp->getData());
            root->setRightChild(this->deleteMin(root->getRightChild()));
        }
        delete temp;
    }
    return root;
}

template <class K, class D>
void BST<K, D>::clearHelp(BinNode<K, D> *root)
{
    if (root == nullptr)
    {
        return;
    }
    clearHelp(root->getLeftChild());
    clearHelp(root->getRightChild());
    delete root;
}

template <class K, class D>
void BST<K, D>::printHelp(BinNode<K, D> *root, ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->isLeaf())
    {
        out << root->getData();
    }
    else
    {
        out << root->getData() << "(";
        printHelp(root->getLeftChild(), out);
        out << ")(";
        printHelp(root->getRightChild(), out);
        out << ")";
    }
}

template <class K, class D>
void BST<K, D>::preorderHelp(BinNode<K, D> *root, ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    out << root->getData() << " ";
    preorderHelp(root->getLeftChild(), out);
    preorderHelp(root->getRightChild(), out);
}

template <class K, class D>
void BST<K, D>::inorderHelp(BinNode<K, D> *root, ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    inorderHelp(root->getLeftChild(), out);
    out << root->getData() << " ";
    inorderHelp(root->getRightChild(), out);
}

template <class K, class D>
void BST<K, D>::postorderHelp(BinNode<K, D> *root, ostream &out)
{
    if (root == nullptr)
    {
        return;
    }
    postorderHelp(root->getLeftChild(), out);
    postorderHelp(root->getRightChild(), out);
    out << root->getData() << " ";
}

//=============================================end of private helper functions============================================

template <class K, class D>
BST<K, D>::BST()
{
    this->root = nullptr;
    this->nodeCount = 0;
}

template <class K, class D>
BST<K, D>::~BST()
{
    this->clear();
}

template <class K, class D>
void BST<K, D>::clear()
{
    this->clearHelp(this->root);
}

template <class K, class D>
D BST<K, D>::find(K key)
{
    return this->findHelp(this->root, key);
}

template <class K, class D>
void BST<K, D>::insert(K key, D data)
{
    this->root = this->insertHelp(this->root, key, data);
}

template <class K, class D>
int BST<K, D>::remove(K key)
{
    if (this->find(key) == NULL)
    {
        return 0;
    }
    this->root = this->removeHelp(this->root, key);
    return 1;
}

template <class K, class D>
int BST<K, D>::length()
{
    return this->nodeCount;
}

template <class K, class D>
void BST<K, D>::print(ostream &out)
{
    this->printHelp(this->root, out);
}

template <class K, class D>
void BST<K, D>::preorder(ostream &out)
{
    this->preorderHelp(this->root, out);
}

template <class K, class D>
void BST<K, D>::inorder(ostream &out)
{
    this->inorderHelp(this->root, out);
}

template <class K, class D>
void BST<K, D>::postorder(ostream &out)
{
    this->postorderHelp(this->root, out);
}
