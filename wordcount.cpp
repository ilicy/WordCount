#include<stdio.h>
#include <string.h>


int main(void)
{
    FILE *pFile;
    char ch=0;
    unsigned int letter_cnt=0;//ͳ��Ӣ���ַ�
    unsigned int word_cnt=0;//ͳ�Ƶ���
    unsigned int row_cnt=0;//ͳ����
    unsigned int ch_cnt=0;//ͳ�������ַ����ų����з���
    bool word_flag=false;
    pFile=fopen("data.txt","r");
    ch=fgetc(pFile);//���ļ��ж�ȡһ���ַ�
    if( !feof(pFile) ) //�ļ�������ǿյģ����ٶ���һ��
    {
        row_cnt++;
    }
    while( !feof(pFile) )//�ж��ļ��Ƿ����
    {
        if( (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') )//��ĸ
    {
    letter_cnt++;
    word_flag=true;
    }
    else if( word_flag )//�жϵ���
    {
        word_cnt++;
        word_flag=false;
    }
    if( ch=='\n' )//����
    {
        row_cnt++;
    }
    else
    {
        ch_cnt++;
    }
        ch=fgetc(pFile);//���ļ��ж�ȡһ���ַ�
    }

    char enter[100];
    scanf("%s",&enter);

    if(strcmp(enter,"wc.exe-word_data.txt")==0)
    {
        printf("������:%d\n",word_cnt);
    }

    if(strcmp(enter,"wc.exe-row_data.txt")==0)
    {
        printf("����:%d\n",row_cnt);
    }

    if(strcmp(enter,"wc.exe-letter_data.txt")==0)
    {
        printf("�ַ���:%d\n",letter_cnt);
    }

    fclose(pFile);
    return 0;
    }
