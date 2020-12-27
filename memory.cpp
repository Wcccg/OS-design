#include <bits/stdc++.h>
using namespace std;

//�ڴ�� 
typedef struct MCB {
    string name = "untitled";	//�̵߳����� 
    int size = 1;						//ռ�ô�С
    int type = -1;						//�ļ����� 
    string content = "null";			//���� 
    bool is_empty = true;
    
} MCB;
MCB mcb[64];		//64�� 

typedef struct Page {
    string name = "untitle";
    int type = -1; 
    int size = 1;
    int is_empty = true;
    int recent_used = 0;	//���ʹ����� 
} Page;
Page page[8];		//ÿ���̷߳���8���飬���8ҳ 

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


//LRUҳ���û��㷨,���ر��һ���ҳ 
int LRU(){
	int i;
	for(i=0;i<8;i++){
		if(page[i].recent_used==0){
//			for(int j=i;j<8;j++){
//				int k=i*8+j;
//				int create_file(mcb[k].name, mcb[k].size, mcb[k].type, mcb[k].content);	//����һ�ȥ 
//			}	
			return i;
		}else{
			page[i].recent_used = 0;
		}
	}
	if(i==8)
		return LRU();
}

//Ϊ�̷߳����ڴ�飬���ط���ĵ�һ���ڴ�� 
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

//�����ڴ�� 
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

//Ϊ�����ļ������ڴ� 
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

//���ļ������ݶ�ȡ���ڴ�����ʾ
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
			}else{			//ҳ���û�
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

//Ϊ�ļ������ڴ� 


int main(){
	show_data("kk");
	show_page();

	return 0;
}
