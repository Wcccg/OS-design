#ifndef DISK_H_
#define DISK_H_
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct FCB
{
    string file_name = "untitled";
    int size = 1;
    int type = 1;
    string content = "null";
    bool is_empty = true;
    int p[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int belong = -1;
} FCB;

// 声明全局变量
FCB fcb;
vector<FCB> disk(1024, fcb);

// 生成一个[from, to)的随机整数
int random_num(int from = 100, int to = 1024)
{
    srand(time(0));
    int random_n = (rand() % (to - from)) + from;
    return random_n;
}

// 进一层封装
int random_num_type(int type = 1)
{
    int random_n;
    if (type == 2)
    {
        random_n = random_num(0, 100);
    }
    else
    {
        random_n = random_num();
    }
    return random_n;
}
// 寻找一块空的磁盘
int random_free(int type = 1)
{
    int area;
    int random_f;
    random_f = random_num_type(type);
    if (type == 2)
    {
        area = 124;
    }
    else
    {
        area = 1024;
    }
    while (!disk[random_f].is_empty)
    { // 如果此块不空，则寻找下一块
        random_f = (random_f + 1) % area;
    }
    return random_f;
}
//参数： 文件名，文件大小，文件，种类( 0：目录，1：文件，2：对换区) ，内容    返回值：文件索引所在块号
int create_file(const string &file_name, int size = 4, int type = 1, string content = "null")
{
    for (int j = 0; j < 1024; ++j)
    {
        if (disk[j].file_name == file_name)
        {
            return -1;
        }
    }
    int main_block = random_free(type);
    int temp_block;
    disk[main_block].file_name = file_name;
    disk[main_block].size = size; // 需要多少块
    disk[main_block].is_empty = false;
    disk[main_block].type = type;
    disk[main_block].belong = main_block;
    disk[main_block].content = content;
    for (int i = 0; i < size; ++i)
    {
        temp_block = random_free(1);
        disk[temp_block].belong = main_block;
        disk[temp_block].is_empty = false;
        disk[main_block].p[i] = temp_block;
    }
    return main_block;
}
// 删除文件，删除成功返回true，否则返回false
bool del_file(string name)
{
    bool flag = false;
    for (int i = 0; i < 1024; ++i)
    {
        if (disk[i].file_name == name)
        {
            flag = true;
            for (int j = 0; j < disk[i].size; ++j)
            {
                // 删除指向的块
                disk[disk[i].p[j]].is_empty = true;
                disk[disk[i].p[j]].belong = -1;
                disk[i].p[j] = -1;
            }
            // 删除自己
            disk[i].is_empty = true;
            disk[i].belong = -1;
            disk[i].content = "null";
            disk[i].file_name = "untitled";
            disk[i].size = 1;
            disk[i].type = 1;
        }
    }
    return flag;
}
// 查找文件，并返回内容和块号，返回值为pair<string, int>，string为内容，int为块号
pair<string, int> find_file(string name)
{
    pair<string, int> result;
    for (int i = 0; i < 1024; ++i)
    {
        if (disk[i].file_name == name)
        {
            result.first = disk[i].content;
            result.second = disk[i].belong;
            return result;
        }
    }
    return result;
}
// 位示图法展示磁盘
void show_disk()
{
    cout << setw(9) << setfill(' ') << ' ';
    for (int j = 0; j < 10; ++j)
    {
        cout << setw(8) << setfill(' ') << j;
    }
    cout << endl;
    cout << setw(8) << setfill(' ') << 0 << '|';
    for (int i = 0; i < 1024; ++i)
    {
        if (disk[i].is_empty)
        {
            cout << setw(8) << setfill(' ') << 0;
        }
        else
        {
            if (disk[i].file_name == "untitled")
            {
                cout << setw(8) << setfill(' ') << disk[i].belong;
            }
            else
            {
                cout << setw(8) << setfill(' ') << disk[i].file_name;
            }
        }
        if (!((i + 1) % 10))
        {
            cout << endl;
            cout << setw(8) << setfill(' ') << (i + 1) / 10 << '|';
        }
    }
    cout << endl;
}

// int main()
// {
//     pair<string, int> temp_pair;
//     create_file("xhx", 4, 1, "I am kitty!");
//     del_file("xhx");
//     temp_pair = find_file("xhx");
//     cout << temp_pair.first << temp_pair.second << endl;
//     show_disk();
//     system("pause");
//     return 0;
// }

#endif