#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <process.h> //�h������禡�w

using namespace std;

void OpenFile(char *st);
void gotoxy(int x, int  y);
void SetConsoleSize(int w,int h);
void SetCursorVisible(BOOL Visible, DWORD Size);

void anime_show(int *a){
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
		Sleep(*a);
	}
}

int main(){
	int Num1 = 50;
	SetConsoleSize(650,900);
	SetCursorVisible(false,1);
	_beginthread(anime_show, 0, &Num1);
	
	int key1,key2;
	while(1){
		if (!kbhit())
			key1= getch();
			
		if (key1 == 0 || key1==224){
			key2 = getch();
			switch(key2){
				case 72:
					if(Num1 > 0)
						Num1-=50;
				break;
				case 80:
					if(Num1 <= 1500)
						Num1+=50;
				break;
			}
		}else{
		}
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

void gotoxy(int x, int  y){
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void SetConsoleSize(int w,int h){
	HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, w, h, TRUE);
}

void SetCursorVisible(BOOL Visible, DWORD Size){
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = Visible; // �O�_�i��
        cci.dwSize = Size; // �]�w�j�p,1~100
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
