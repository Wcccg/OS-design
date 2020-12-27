#include <bits/stdc++.h>
#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_
using namespace std;

struct node
{
    string name = "";
    string ch = "NULL";
    bool isFile = 0;
    int size = 0;
    int position = -1;
    int state = 0;
    string con = "";
    node *parent = NULL;
    node *child = NULL;
    node *next = NULL;
};

#endif