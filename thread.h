#ifndef THREAD_H_
#define THREAD_H_
#include <thread>
#include <mutex>
#include <windows.h>
#include "run.h"
#include <string>
#include "THrun.h"
#include <iostream>
using namespace std;

mutex m;
mutex m1, m2, m3;

void create_thread(node *n, string y)
{
	m2.lock();
	runCreate1(n, y);
	Sleep(3000);
	m2.unlock();
	cout << y << " create finished." << endl;
}

void del_thread(node *n, string y)
{
	m2.lock();
	m3.lock();
	runDel(n, y);
	m3.unlock();
	m2.unlock();
	cout << y << " delete finished." << endl;
}

void run_thread(node *n, string str)
{
	showMem();
	showDisk();
	Sleep(6000);
	runOpen(n, str);
	cout << str << " open finished." << endl;
	showMem();
	showDisk();
	runClose(n, str);
}

void test_th1()
{
	m.lock();
	for (int i = 0; i < 50; i++)
	{
		Sleep(100);
		cout << i << ' ';
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	m.unlock();
}

void test_th2()
{
	for (int i = 0; i < 50; i++)
	{
		Sleep(100);
		cout << i << ' ';
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

#endif
// int main()
// {
// 	srand(time(NULL));
// 	node *root;
// 	root = init();
// 	thread th(create_thread, root, "TThread");
// 	thread th2(create_thread, root, "TThread");
// 	th.join();
// 	th2.join();
// 	system("pause");
// }

/*
�ɸ��ӵĲ��֣�
������ж���ļ�������ʹ�����²��֣�
cin>>run_number;
cout<<"������Ҫͬʱ���е�"<<run_number<<"���ļ�:"<<endl;
thread threads[run_number];
string like_file;
for (int i=0; i<run_number; ++i){
	cin>>like_file;
	threads[i] = thread(run_thread,i,like_file);
}
for (auto& th : threads) th.join();

ͬʱrun_thread�������
while(true){
	if (m.try_lock()){
		m2.lock();
		cout<<id<<"���߳�����"<<like_file<<"�����ɹ���"<<endl;
		m2.unlock();
		break;
	}
	else{
		m2.lock();
		cout<<id<<"���߳�����"<<like_file<<"����ʧ�ܡ�"<<endl;
		m2.unlock();
	}
}

*/
