#include <bits/stdc++.h>
using namespace std;

//内存块 
typedef struct MCB {
    string name = "untitled";	//线程的名字 
    int size = 1;						//占用大小
    int type = -1;						//文件类型 
    string content = "null";			//内容 
    bool is_empty = true;
    
} MCB;
MCB mcb[64];		//64块 

typedef struct Page {
    string name = "untitle";
    int type = -1; 
    int size = 1;
    int is_empty = true;
    int recent_used = 0;	//最近使用情况 
} Page;
Page page[8];		//每个线程分配8个块，最多8页 

void show_page(){
	printf("page\tname\t\tis_empty\tsize\trecent_used\n");
	for(int i=0;i<8;i++){
		cout<<i<<'\t'<<page[i].name<<"\t\t"<<page[i].is_empty
			<<"\t\t"<<page[i].size<<"\t\t"<<page[i].recent_used<<endl;
	}
	printf("\n");
}

void show_mcb(){
	printf("mcb is_empty\n");
	for(int i=0;i<64;i++){
		printf("%d ",mcb[i].is_empty);
		if((i+1)%8==0)
			printf("\n");
	}
}


//LRU页面置换算法,返回被兑换的页 
int LRU(){
	int i;
	for(i=0;i<8;i++){
		if(page[i].recent_used==0){
//			for(int j=i;j<8;j++){
//				int k=i*8+j;
//				int create_file(mcb[k].name, mcb[k].size, mcb[k].type, mcb[k].content);	//调入兑换去 
//			}	
			return i;
		}else{
			page[i].recent_used = 0;
		}
	}
	if(i==8)
		return LRU();
}

//为线程分配内存块，返回分配的第一个内存块 
int alloc_thread(string thread_name,int size = 4,int type = 2, string content = "null"){
	int i;
	for(i=0;i<64;i=i+8){
		if(mcb[i].is_empty)
			break;
	}
	if(i==64){
		int k = LRU();
		i = k*8;
	}
		
	page[i/8].name = thread_name;
	page[i/8].size = 4;
	page[i/8].type = 2;
	page[i/8].recent_used = 1;
	page[i/8].is_empty = false;
	for(int j=0;j<8;j++){
		mcb[i+j].name = thread_name;
		mcb[i+j].size = size;
		mcb[i+j].is_empty = false;
		mcb[i+j].type = type;
		mcb[i+j].content = content;
	}
	return i;
}

//回收内存块 
void free(string name){
	for(int i=0;i<8;i++){
		if(page[i].name == name){
			page[i].name = "untitle";
			page[i].is_empty = true;
			page[i].recent_used = 0;
			page[i].size = 0;
			page[i].type = -1;
			for(int j=0;j<8;j++){
				mcb[i+j].name = "untitle";
				mcb[i+j].size = 1;
				mcb[i+j].is_empty = true;
				mcb[i+j].type = -1;
				mcb[i+j].content = "null";
			};
		}			
	}
}

//为数据文件分配内存 
int alloc_datafile(){
	int i;
	for(i=0;i<64;i=i+8){
		if(mcb[i].is_empty)
			break;
	}
	if(i==64){
		int k = LRU();
		i = k*8;
	}
	return i;
}

//将文件中数据读取到内存中显示
void show_data(string file_name){
	int i = alloc_datafile();
	page[i/8].name = file_name;
	page[i/8].is_empty = false;
	page[i/8].recent_used = 1;
	page[i/8].type = 1;
	mcb[i].name = file_name;
	mcb[i].is_empty = false;
	mcb[i].type = 1;
	int cnt=0,num=0;
	FILE *fp;
	fp = fopen("f1.txt" , "r");
	if(fp == NULL)
    	cout<<"cannot find file "<<file_name<<endl;
	char ch;
	while( (ch=fgetc(fp))!=EOF ){
    	printf("%c",ch);
    	cnt++;
    	if(cnt==4096){
      		num++;
      		mcb[i].size = 4096;
      		if(num<8){
      			i++;
				mcb[i].name = file_name;
				mcb[i].is_empty = false;
				mcb[i].type = 1;
			}else{			//页面置换
				page[i/8].size = 4096*8;
			 	i=alloc_datafile();
			 	num=0;
			 	page[i/8].name = file_name;
				page[i/8].is_empty = false;
				page[i/8].recent_used = 1;
				page[i/8].type = 1;
				mcb[i].name = file_name;
				mcb[i].is_empty = false;
				mcb[i].type = 1;	
			}
			cnt=0;
		}
	}
	page[i].size = 4096*num+cnt;
	mcb[i].size = cnt;
	
	printf("\n\n\n");
	fclose(fp);
	
}

//为文件分配内存 


int main(){
	show_data("kk");
	show_page();

	return 0;
}
