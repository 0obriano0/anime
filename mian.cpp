#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <process.h> //�h������禡�w
#include "mmsystem.h"//?�J?��?��� 
#pragma comment(lib,"winmm.lib")//?�J?��?���? 

#define buffer_size 16384
#define buffer_size_1 16384

//-fpermissive
// link -lwinmm


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
char buffer[buffer_size];
int move = 0;
int main(){
	
	
	setvbuf(stdout,buffer,_IOFBF,buffer_size);
	
	char buf[255];
	mciSendString(("open Brain_Power.mp3 alias MUSIC"),buf,sizeof(buf),0);
	mciSendString("play MUSIC repeat",NULL,0,0); 
	
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
					if(Num1 > 600)
						Num1-=10;
					else if(Num1 > 0)
						Num1-=50;
				break;
				case 80:
					if(Num1 < 600)
						Num1+=50;
					else if(Num1 < 1500)
						Num1+=10;
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
	bool get_enter = false;
	while((ch = fgetc(fp)) != EOF){ //Ū������ɮ� (�����ɮ׵���) , �C��Ū�X�@�Ӧr��
		if(get_enter){
			for(int loopnum1 = 0;loopnum1 < move*2;loopnum1++)
				putc(' ',stdout);
			get_enter = false;
		}
		if(ch == '\n')
			get_enter = true;
    	fputc(ch,stdout);  //fputc(�g�J�r��, stdout���зǿ�X/�ù� )
	}
	
	fflush(stdout);
	move++;
	if(move == 50){
		move = 0;
		system("cls");
	}
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
