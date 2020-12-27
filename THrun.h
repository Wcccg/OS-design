#ifndef THRUN_H_
#define THRUN_H_
#include "dataStruct.h"
#include "memory.h"
#include "init.h"
using namespace std;

void runCreate(node *n, string str);
void runCreate1(node *n, string str);
void runDel(node *n, string str);
void runOpen(node *n, string str);

void runCreate(node *n, string str)
{
    node *n1 = new node;
    n1->name = str;
    n1->parent = n;
    n1->isFile = 1;
    n1->size = 4;
    cout << "Please input a string:";
    string s, s1;
    getline(cin, s1);
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != ' ')
            s += s1[i];
    int x = alloc_thread(str);
    alloc_file(str, 4, 2, s, x);
    n1->position = create_file(str, 4, 1, s);
    free(str);
    n1->con = s;
    if (!n->child)
    {
        n->child = n1;
        n->ch = str;
    }
    else
    {
        n = n->child;
        while (n->next)
            n = n->next;
        n->next = n1;
    }
}

void runCreate1(node *n, string str)
{
    node *n1 = new node;
    n1->name = str;
    n1->parent = n;
    n1->isFile = 1;
    n1->size = 4;
    string s = "It's_a_test.";
    int x = alloc_thread(str);
    alloc_file(str, 4, 2, s, x);
    n1->position = create_file(str, 4, 1, s);
    free(str);
    n1->con = s;
    if (!n->child)
    {
        n->child = n1;
        n->ch = str;
    }
    else
    {
        n = n->child;
        while (n->next)
            n = n->next;
        n->next = n1;
    }
}

void runDel(node *n, string str)
{
    node *n1 = findNode(n, str);
    if (!n1)
    {
        cout << "Invalid command." << endl;
        return;
    }
    if (!n1->parent)
    {
        cout << "Invalid command." << endl;
        return;
    }
    if (n1->parent == n && !n1->child && !Mfind(str))
    {
        del_file(str);
        node *n2 = n->child;
        while (n2->next != n1 && n2->next)
            n2 = n2->next;
        if (!n2->next)
            n2 = NULL;
        if (n2)
            n2->next = n1->next;
        if (n->child == n1)
        {
            n->child = n1->next;
            n->ch = n1->next->name;
        }
        free(n1);
    }
    else
        cout << "Invalid command." << endl;
}

void runOpen(node *n, string str)
{
    node *n1 = findNode(n, str);
    if (!n1)
    {
        cout << "Invalid command." << endl;
        return;
    }
    if (n1->parent == n && n1->isFile)
    {
        int x = alloc_thread(str);
        pair<string, int> temp_pair;
        temp_pair = find_file(str);
        alloc_file(str, 4, 2, temp_pair.first, x);
        cout << temp_pair.first << endl;
    }
    else
        cout << "Invalid command." << endl;
}

#endif