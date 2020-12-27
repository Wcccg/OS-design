#ifndef THREAD_H_
#define THREAD_H_
#include <thread>
#include <mutex>
#include <windows.h>
#include "run.h"
#include "THrun.h"
#include <iostream>
using namespace std;

mutex m1, m2;
void create_thread(node *n, string y)
{
	m1.lock();
	runCreate(n, y);
	m1.unlock();
}

void del_thread(node *n, string y)
{
	m2.lock();
	runDel(n, y);
	m2.unlock();
}

void run_thread(node *n, string str)
{
	runOpen(n, str);
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
