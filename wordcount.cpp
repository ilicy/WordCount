#include<stdio.h>
#include <string.h>


int main(void)
{
    FILE *pFile;
    char ch=0;
    unsigned int letter_cnt=0;//统计英文字符
    unsigned int word_cnt=0;//统计单词
    unsigned int row_cnt=0;//统计行
    unsigned int ch_cnt=0;//统计所有字符（排除换行符）
    bool word_flag=false;
    pFile=fopen("data.txt","r");
    ch=fgetc(pFile);//从文件中读取一个字符
    if( !feof(pFile) ) //文件如果不是空的，最少都有一行
    {
        row_cnt++;
    }
    while( !feof(pFile) )//判断文件是否结束
    {
        if( (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') )//字母
    {
    letter_cnt++;
    word_flag=true;
    }
    else if( word_flag )//判断单词
    {
        word_cnt++;
        word_flag=false;
    }
    if( ch=='\n' )//换行
    {
        row_cnt++;
    }
    else
    {
        ch_cnt++;
    }
        ch=fgetc(pFile);//从文件中读取一个字符
    }

    char enter[100];
    scanf("%s",&enter);

    if(strcmp(enter,"wc.exe-word_data.txt")==0)
    {
        printf("单词数:%d\n",word_cnt);
    }

    if(strcmp(enter,"wc.exe-row_data.txt")==0)
    {
        printf("行数:%d\n",row_cnt);
    }

    if(strcmp(enter,"wc.exe-letter_data.txt")==0)
    {
        printf("字符串:%d\n",letter_cnt);
    }

    fclose(pFile);
    return 0;
    }
