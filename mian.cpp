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
	
	//�Y�L���� c:\\test1.txt , �e���|�@�{�ӹL(�S��ܰT��) 
	if((fp=fopen( st , "r")) == NULL) printf("���{���䤣���ɮסA�Ч�{���]�p�̸߰�");;

	while((ch = fgetc(fp)) != EOF) //Ū������ɮ� (�����ɮ׵���) , �C��Ū�X�@�Ӧr��  
    fputc(ch,stdout);  //fputc(�g�J�r��, stdout���зǿ�X/�ù� )  

	fclose(fp);  //���� 
}

void gotoxy(int x, int  y)
{
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
