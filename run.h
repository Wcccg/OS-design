#ifndef RUN_H_
#define RUN_H_
#include <bits/stdc++.h>
#include "init.h"
#include "memory.h"
#include "runModule.h"
#include "THrun.h"
#include "thread.h"
using namespace std;

int getPosition();
string getPath(node *n, string str);        // 返回当前路径
bool runExit();                             // 退出 run()
void runDir(node *n);                       // 显示当前路径下文件以及子文件夹
node *runCd(node *n, string str);           // 路径跳转
void runMd(node *n, string str);            // 新建文件夹
void runHelp();                             // 显示帮助文档
void updateFile(node *n);                   // 更新目录存储文件
void run(node *n, node *root);              // 运行命令行窗口

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
    else if (n1->parent == n && !n1->isFile)
        return n1;
    else
    {
        cout << "Invalid command." << endl;
        return n;
    }
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
        cout << "NULL" << ' ';
    else
    {
        while (n1->next != n && n1->next)
            n1 = n1->next;
        cout << n1->name << ' ';
    }
    if (n->isFile)
        cout << n->con;
    cout << endl;
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
    if (x == "")
    {
    }
    else if (x == "Test1" && y == "")
    {
        Test1(n);
    }
    else if (x == "Test2" && y == "")
    {
        Test2(n);
    }
    else if (x == "Test3" && y == "")
    {
        Test3(n);
    }
    else if (x == "exit" && y == "")
    {
        if (runExit())
            return;
    }
    else if (x == "close" && y != "")
    {
        runClose(n, y);
    }
    else if (x == "open" && y != "")
    {
        runOpen(n, y);
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
    {
        showMem();
    }
    else if (x == "showDisk" && y == "")
    {
        showDisk();
    } 
    else if (x == "del" && y != "")
    {
        runDel(n, y);
    }
    else if (x == "md" && y != "")
    {
        runMd(n, y);
    }
    else if (x == "create" && y != "")
    {
        runCreate(n, y);
    }
    else if (x == "help" && y == "")
    {
        runHelp();
    }
    else
        cout << "Invalid command." << endl;
    freopen("fileTree.txt", "w", stdout);
    updateFile(root);
    freopen("con", "w", stdout);
    run(n, root);
}

#endif