#include <bits/stdc++.h>
#include "init.cpp"
using namespace std;

int getPosition()
{
    return rand() % 900;
}

string getPath(node *n, string str)
{
    if (!n->parent)
        return n->name + ":/";
    return getPath(n->parent, str) + n->name + '/';
}

bool runExit()
{
    string x = "";
    string y = "";
    string s = "";
    cout << "Enter 'Y' or 'y' to exit:";
    getline(cin, s);
    stringstream ss1(s);
    ss1 >> x;
    if (ss1)
        ss1 >> y;
    if (y == "" && (x == "Y" || x == "y"))
        return true;
    return false;
}

void runDir(node *n)
{
    node *n1 = n->child;
    if (n1)
    {
        cout << n1->name << ' ';
        while (n1->next)
        {
            n1 = n1->next;
            cout << n1->name << ' ';
        }
        cout << endl;
    }
}

void runRun(node *n, string str)
{
    node *n1 = findNode(n, str);
    if (n1->parent == n)
    {
        cout << str << " start running." << endl;
        // ���г���
    }
    else
        cout << "Invalid command." << endl;
}

node *runCd(node *n, string str)
{
    if (str == "../")
    {
        if (n->parent)
            return n->parent;
        else
        {
            cout << "Invalid command." << endl;
            return n;
        }
    }
    node *n1 = findNode(n, str);
    if (!n1)
    {
        cout << "Invalid command." << endl;
        return n;
    }
    else if (n1->parent == n)
        return n1;
    else
    {
        cout << "Invalid command." << endl;
        return n;
    }
}

void showMem()
{
}

void showDisk()
{
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
    if (n1->parent == n && !n1->child && !n1->state)
    {
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

void runMd(node *n, string str)
{
    node *n1 = new node;
    n1->name = str;
    n1->parent = n;
    if (!n->child)
        n->child = n1;
    else
    {
        n = n->child;
        while (n->next)
            n = n->next;
        n->next = n1;
    }
}

void runCreate(node *n, string str)
{
    node *n1 = new node;
    n1->name = str;
    n1->parent = n;
    n1->isFile = 1;
    n1->size = 1;
    n1->position = getPosition();
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

void runRename(node *n, string str)
{
    node *n1 = findNode(n, str);
    if (n1->parent == n && !n1->state)
        n1->name = str;
    else
        cout << "Invalid command." << endl;
}

void runHelp()
{
    fstream in;
    in.open("help.txt", ios::app | ios::in);
    string s;
    while (getline(in, s))
        cout << s << endl;
}

void updateFile(node *n)
{
    if (n == NULL)
        return;
    cout << n->name << ' ';
    cout << n->isFile << ' ';
    cout << n->size << ' ';
    cout << n->position << ' ';
    node *n1 = NULL;
    if (n->parent)
    {
        cout << n->parent->name;
        n1 = n->parent->child;
    }
    else
        cout << "NULL";
    cout << ' ' << n->ch << ' ';
    if (n == n1 || !n1)
        cout << "NULL" << endl;
    else
    {
        while (n1->next != n && n1 ->next)
            n1 = n1->next;
        cout << n1->name << endl;
    }
    updateFile(n->child);
    updateFile(n->next);
}

void run(node *n, node *root)
{
    cout << getPath(n, "");
    string s;
    getline(cin, s);
    stringstream ss(s);
    string x;
    string y;
    ss >> x;
    if (ss)
        ss >> y;
    if (x == "exit" && y == "")
    {
        if (runExit())
            return;
    }
    else if (x == "run" && y != "")
    {
        runRun(n, y);
    }
    else if (x == "dir" && y == "")
    {
        runDir(n);
    }
    else if (x == "cd" && y != "")
    {
        node *n1 = runCd(n, y);
        if (n1)
            n = n1;
        else
            cout << "Invalid command." << endl;
    }
    else if (x == "showMem" && y == "")
        showMem();
    else if (x == "showDisk" && y == "")
        showDisk();
    else if (x == "del" && y != "")
        runDel(n, y);
    else if (x == "md" && y != "")
        runMd(n, y);
    else if (x == "create" && y != "")
        runCreate(n, y);
    else if (x == "rename" && y != "")
        runRename(n, y);
    else if (x == "help" && y == "")
        runHelp();
    else
        cout << "Invalid command." << endl;
    freopen("fileTree.txt", "w", stdout);
    updateFile(root);
    freopen("con", "w", stdout);
    run(n, root);
}