#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <conio.h>
	
using namespace std;

typedef struct
{
	int x,y;
	char ch;
}STU;
STU st[100];

void gotoxy(int x, int y)  
{  
    HANDLE hout;  
    COORD pos;  
    pos.X = x;  
    pos.Y = y;  
	
    hout = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleCursorPosition(hout, pos);  
}  
 
/*隐藏光标*/  
void show_cursor(int hide)  
{  
    CONSOLE_CURSOR_INFO cciCursor;  
    HANDLE hout;  
	
    hout = GetStdHandle(STD_OUTPUT_HANDLE);  
    if(GetConsoleCursorInfo(hout, &cciCursor))  
    {  
        cciCursor.bVisible = hide;  
        SetConsoleCursorInfo(hout, &cciCursor);  
    }  
}  
 
/*设置颜色*/  
void set_color(int color)  
{  
	
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  
}  

void cd()//进入界面
{
	set_color(3);
	
	int i,j;
	cout<<endl<<endl<<endl<<endl;
	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
	cout<<"               ★***★         Executive the Precess...     ★***★"<<endl; 
	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
	cout<<endl<<endl;
	cout<<"               ||★★★★★★★★★★★★★★★★★★★★★★★★||"<<endl;
	cout<<"               ||★                                            ★||"<<endl;
	cout<<"               ||★              计算机与通信工程学院          ★||"<<endl;
	cout<<"               ||★                计算机科学与技术            ★||"<<endl;
	cout<<"               ||★              制作团队: 计科1806 03题       ★||"<<endl;
	cout<<"               ||★                                            ★||"<<endl;
	cout<<"               ||★★★★★★★★★★★★★★★★★★★★★★★★||"<<endl<<endl;
	{	
		cout<<endl<<"               正";
		for(i=0;i<80000000;i++);
		cout<<"在";
		for(i=0;i<80000000;i++);
		cout<<"初";
		for(i=0;i<80000000;i++);
		cout<<"始";
		for(i=0;i<80000000;i++);
		cout<<"化";
		for(i=0;i<80000000;i++);
		cout<<"中";
		for(i=0;i<80000000;i++);
		cout<<"，";
		for(i=0;i<80000000;i++);
		cout<<"请";
		for(i=0;i<80000000;i++);
		cout<<"稍";
		for(i=0;i<80000000;i++);
		cout<<"等";
		for(i=0;i<80000000;i++);
		for(j=0;j<=6;j++)
		{
		cout<<".";
		for(i=0;i<80000000;i++);
		}
		for(i=0;i<8*80000000;i++);
		
		cout<<endl<<endl;
cout<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends;
	}
	for(j=0;j<=50;j++)
	{
		cout<<"<";
		for(i=0;i<=50000000;i++);
	}
	system("cls");
}

void ex()//表示进程执行过程 (意思意思) 
{
	int i,j;
	show_cursor(0);
	srand(time(NULL));
	//初始化结构体 
	for (i=0;i<100;i++)
	{
		st[i].x = rand()%80;
		st[i].y = rand()%20;
		st[i].ch = rand()%(49-47)+48;
	}
	
	while(!kbhit()) // 输入任意键结束 
	{
		for (i=0;i<100;i++)
		{
			gotoxy(st[i].x,st[i].y);
			set_color(0x2);
			putchar(st[i].ch);
			gotoxy(st[i].x,st[i].y-5);
			putchar(' ');
			st[i].y++;
			st[i].ch = rand()%(49-47)+48;
			if (st[i].y-5>=18)
			{
				gotoxy(st[i].x,st[i].y-1);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-2);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-3);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-4);
				putchar(' ');
				gotoxy(st[i].x,st[i].y-4);
				putchar(' ');
			}
			if (st[i].y > 23)
			{
				st[i].x = rand()%80;
				st[i].y = rand()%20;
			}
			gotoxy(st[i].x,st[i].y);
			set_color(0xA);
			putchar(st[i].ch);
		}
		Sleep(120);
	
	} 
	system("cls");
}
 

void mutex_function()//内存管理 判断是否访问资源互斥 (感觉跟内观管理相关)
{
	system("cls");
	cout << "资源被占用，当前进程不可访问！";
	//进入阻塞队列 
}



int main() 
{
	
	cd();
	ex(); 
	cout <<"The Process finish!"; 
	
	return 0;
}
