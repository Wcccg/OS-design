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
 
/*���ع��*/  
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
 
/*������ɫ*/  
void set_color(int color)  
{  
	
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  
}  

void cd()//�������
{
	set_color(3);
	
	int i,j;
	cout<<endl<<endl<<endl<<endl;
	cout<<"               ���������������������������"<<endl;
	cout<<"               ��***��         Executive the Precess...     ��***��"<<endl; 
	cout<<"               ���������������������������"<<endl;
	cout<<endl<<endl;
	cout<<"               ||�������������������������||"<<endl;
	cout<<"               ||��                                            ��||"<<endl;
	cout<<"               ||��              �������ͨ�Ź���ѧԺ          ��||"<<endl;
	cout<<"               ||��                �������ѧ�뼼��            ��||"<<endl;
	cout<<"               ||��              �����Ŷ�: �ƿ�1806 03��       ��||"<<endl;
	cout<<"               ||��                                            ��||"<<endl;
	cout<<"               ||�������������������������||"<<endl<<endl;
	{	
		cout<<endl<<"               ��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"ʼ";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
		for(i=0;i<80000000;i++);
		cout<<"��";
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

void ex()//��ʾ����ִ�й��� (��˼��˼) 
{
	int i,j;
	show_cursor(0);
	srand(time(NULL));
	//��ʼ���ṹ�� 
	for (i=0;i<100;i++)
	{
		st[i].x = rand()%80;
		st[i].y = rand()%20;
		st[i].ch = rand()%(49-47)+48;
	}
	
	while(!kbhit()) // ������������� 
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
 

void mutex_function()//�ڴ���� �ж��Ƿ������Դ���� (�о����ڹ۹������)
{
	system("cls");
	cout << "��Դ��ռ�ã���ǰ���̲��ɷ��ʣ�";
	//������������ 
}



int main() 
{
	
	cd();
	ex(); 
	cout <<"The Process finish!"; 
	
	return 0;
}
