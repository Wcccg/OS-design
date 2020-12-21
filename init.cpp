#include <bits/stdc++.h>
#include "dataStruct.cpp"
using namespace std;

node *findNode(node *n, string name)
{
    if (n == NULL || name == "NULL")
        return NULL;
    node *nn = NULL;
    if (n->name == name)
        nn = n;
    if (nn)
        return nn;
    nn = findNode(n->next, name);
    if (nn)
        return nn;
    nn = findNode(n->child, name);
    return nn;
}

node *initTree()
{
    fstream in;
    in.open("fileTree.txt", ios::app | ios::in);
    string s;
    getline(in, s);
    stringstream ss(s);
    string x;
    node *root = new node;
    ss >> x;
    root->name = x;
    ss >> x;
    root->isFile = stoi(x);
    ss >> x;
    root->size = stoi(x);
    ss >> x;
    root->position = stoi(x);
    ss >> x;
    root->parent = findNode(root, x);
    ss >> x;
    root->child = findNode(root, x);
    root->ch = x;
    ss >> x;
    root->next = NULL;
    while (getline(in, s))
    {
        stringstream ss(s);
        node *n = new node;
        node *n1;
        ss >> x;
        n->name = x;
        ss >> x;
        n->isFile = stoi(x);
        ss >> x;
        n->size = stoi(x);
        ss >> x;
        n->position = stoi(x);
        ss >> x;
        n1 = findNode(root, x);
        n->parent = n1;
        if (n1)
            if (n1->ch == n->name)
                n1->child = n;
        ss >> x;
        n->child = findNode(root, x);
        n->ch = x;
        ss >> x;
        n1 = findNode(root, x);
        if (n1)
            n1->next = n;
    }
    return root;
}

node* init()
{
    node *root;
    root = initTree();
    return root;
}