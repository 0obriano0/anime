#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void OpenFile(char *st);
void gotoxy(int x, int  y);

int main(){
	int Num1 = 1;
	while(1){
		char st[100]="data\\image_";
		char buffer[33];
		itoa (Num1,buffer,10);
		strcat(st , buffer);
		strcat(st , ".txt");
		
		gotoxy(0,0);
		OpenFile(st);
		
		Num1++;
		if(Num1 >= 10)
			Num1 = 1;
		Sleep(100);
	}
	return 0;
}


void OpenFile(char *st){
	char ch;
	FILE *fp;
	
	//若無此檔 c:\\test1.txt , 畫面會一閃而過(沒顯示訊息) 
	if((fp=fopen( st , "r")) == NULL) printf("此程式找不到檔案，請找程式設計者詢問");;

	while((ch = fgetc(fp)) != EOF) //讀取整個檔案 (直到檔案結尾) , 每次讀出一個字元  
    fputc(ch,stdout);  //fputc(寫入字元, stdout指標準輸出/螢幕 )  

	fclose(fp);  //關檔 
}

void gotoxy(int x, int  y)
{
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
