#include<windows.h>
#include <iostream>
using namespace std;
#include "mmsystem.h"//?入?音?文件 
#pragma comment(lib,"winmm.lib")//?入?音?文件? 
#include<stdio.h>
void PlayMp3() ;
int main()
{
PlayMp3() ;
PlaySound("D:\\Program Files\\Tencent\\QQ\\Misc\\Sound\\Office\\system.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); 

system("pause"); 

}
void PlayMp3() 
{ 
char buf[128]; 
char str[128] = {0 }; 
int i = 0; 

//use mciSendCommand 
MCI_OPEN_PARMS mciOpen; 
MCIERROR mciError; 
//SetWindowText(NULL,"12345"); 
mciOpen.lpstrDeviceType = "mpegvideo"; 
mciOpen.lpstrElementName = "c:\\WELCOME.WAV"; 
mciError = mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,(DWORD)&mciOpen); 
if(mciError) 
{ 
mciGetErrorString(mciError,buf,128); 
printf("send MCI_OPEN command failed:%s\n",buf); 
return; 
} 
UINT DeviceID = mciOpen.wDeviceID ; 
MCI_PLAY_PARMS mciPlay; 

mciError = mciSendCommand(DeviceID,MCI_PLAY,0 ,(DWORD)&mciPlay); 
if(mciError) 
{ 
printf("send MCI_PLAY command failed\n"); 
return; 
} 
}
