#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define lineLength 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct
{
	int iData;
	char cChar;
	char cChar2;
}Data;

int main(int argc, char** argv) {
	FILE* file;
	
	//�򿪷�ʽ��
	// r ��ֻ����ʽ�򿪣��ļ������Ѿ�����
	// r+ �Զ�д��ʽ�򿪣��ļ��������
	// rb+ �Զ�д��ʽ�򿪣��ļ��Ƕ������ļ����ļ��������
	// rt+ �Զ�д��ʽ�򿪣��ļ����ı��ļ� ���ļ��������
	// w ��д�ķ�ʽ�򿪣�����ļ�ԭ���������ݣ���ʱ������ո��ǣ���������ڣ��½��ļ�
	// w+ �Զ�д��ʽ�򿪣�����ļ�ԭ���������ݣ���ʱ������ո��ǣ���������ڣ��½��ļ�
	// a �Ը��ӷ�ʽ�򿪣�����ļ�ԭ��������ݣ��������ݸ��ӵ�Դ�ļ���β�������������ڣ��½��ļ�
	// a+ �Ը��ӷ�ʽ�ɶ�д�򿪣�����ļ�ԭ��������ݣ��������ݸ��ӵ�Դ�ļ���β�������������ڣ��½��ļ�
	// wb
	// wb+
	// wt+
	// ab+
	// at+
	
	// write text
//	char buffer1[lineLength] = "Hello world!\r\n";
//	char buffer2[lineLength] = "Line2: aaaaaa bbbbb\r\n";
//	
//	file = fopen(".\\a.txt", "wt+");
//	
//	if(file == NULL)
//	{
//		printf("open file a.txt failed\n");
//	}
//	else
//	{
//		printf("open file a.txt successfully\n");
		
		// int fprintf(File *f, const char* format, ...);
		// fprintf(file, "%s", buffer1);
		// fprintf(file, "%s", buffer2);
//	}
	
	
	// read text
//	char buffer[lineLength];
//	file = fopen(".\\a.txt", "rt+");
//	
//	if(file == NULL)
//	{
//		printf("open file a.txt failed.\n");
//	}
//	else
//	{
//		printf("open file a.txt successfully.\n");
//		
//		// int fscanf( FILE *f, const char* format, ...);
//		while(fscanf(file, "%s", buffer) != EOF)
//		{
//			printf("%s:%d\n", buffer, ftell(file));
//		}
//	}

	Data a, b, c;
	
	a.iData = 53;
	a.cChar = 'a';
	a.cChar2 = 'd';
	
	b.iData = 56;
	b.cChar = 'c';
	b.cChar2 = 'e';
	
	file = fopen(".\\c.b", "ab+");
	
	if(file == NULL)
	{
		printf("open file c.b failed.\n");
	}
	else
	{
		// fwrite((void*) p, int size, int count, FILE* f)
		if(fwrite(&a, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
		
		if(fwrite(&b, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
	}
	
	// int fseek(FILE* f, long offset, int origin)
	// origin:
	// 		SEEK_SET ��ͷ��SEEK_CUR ��ǰλ�ã� SEEK_END ��β��ʼ 
	
	fseek(file, sizeof(Data), SEEK_SET);
	
	// fread((void*) p, int size, int count, FILE* f)
	fread(&c, sizeof(Data), 1, file);
	
	printf("%d.%c.%c\n", c.iData, c.cChar, c.cChar2); 
	
	fclose(file);
	
	return 0;
}
