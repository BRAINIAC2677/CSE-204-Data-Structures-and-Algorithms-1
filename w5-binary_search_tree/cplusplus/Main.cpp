#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
using namespace std;

int main()
{
    ifstream in("input.txt", ios::in);
    ofstream out("output.txt", ios::out);
    BST<int, int> bst;
    while (!in.eof())
    {
        char op;
        in >> op;
        if (op == 'F')
        {
            int key;
            in >> key;
            out << (bst.find(key) == NULL ? "False" : "True") << "\n";
        }
        else if (op == 'I')
        {
            int key, data;
            in >> key;
            data = key;
            bst.insert(key, data);
            bst.print(out);
            out << "\n";
        }
        else if (op == 'D')
        {
            int key;
            in >> key;
            int isRemoved = bst.remove(key);
            if (isRemoved)
            {
                bst.print(out);
            }
            else
            {
                out << "Invalid Operation";
            }
            out << "\n";
        }
        else if (op == 'T')
        {
            string s;
            in >> s;
            if (s == "Pre")
            {
                bst.preorder(out);
            }
            else if (s == "In")
            {
                bst.inorder(out);
            }
            else
            {
                bst.postorder(out);
            }
            out << "\n";
        }
    }
    in.close();
    out.close();
    return 0;
}