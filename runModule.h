#ifndef RUNMODULE_H_
#define RUNMODULE_H_

#include "thread.h"
using namespace std;

void Test1(node *n)
{
    thread th1(create_thread, n, "T1.1");
    thread th2(create_thread, n, "T1.2");
    th1.join();
    th2.join();
    thread th3(del_thread, n, "T1.1");
    th3.join();
}

void Test2(node *n)
{
    thread th1(test_th1);
    thread th2(test_th1);
    th1.join();
    th2.join();   
}

void Test3(node *n)
{
    thread th1(test_th2);
    thread th2(test_th2);
    th1.join();
    th2.join();   
}


#endif